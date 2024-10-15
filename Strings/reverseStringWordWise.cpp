#include<bits/stdc++.h>
using namespace std;

void reverseStringWordWise(char input[]) {
    int length = strlen(input);
    int start = 0;

    for (int i=0;i<length/2;i++){
        char temp = input[i];
        input[i] = input[length-i- 1];
        input[length-i-1] = temp;
    }

    for(int i=0;i<length;i++){
        if(input[i]==' '){
            for(int j=start;j<(i+start)/2;j++){
                char temp=input[j];
                input[j]=input[i-j+start-1];
                input[i-j+start-1]=temp;
            }
        
            start=i+1;
        }
    }

    for(int j=start;j<(length+start)/2;j++){
        char temp = input[j];
        input[j] = input[length-j+start-1];
        input[length-j+start-1] = temp;
    }
}