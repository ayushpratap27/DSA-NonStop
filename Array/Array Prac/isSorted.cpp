#include<bits/stdc++.h>
using namespace std;

int isSorted(int n, vector<int> arr) {

    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            return 0;
        }
    }
    return 1;
}


int main(){

}