#include<bits/stdc++.h>
using namespace std;

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    string s1="YES";
    string s2="NO";
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(book[i]+book[j]==target){
                return s1;
            }
        }
    }

    return s2;
}

int main(){

    
}