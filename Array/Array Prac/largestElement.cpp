#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int n) {

    int maxi=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }

    return maxi;
}

int main(){

}