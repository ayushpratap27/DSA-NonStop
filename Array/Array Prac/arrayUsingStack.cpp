#include<bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {     
    vector<string> result;
    int j=1,i=0;
    while(j<=n && i<target.size()){
        if(j==target[i]){
            result.push_back("Push");
            i++;
            j++;
        }
        else if(j!=target[i]){
            result.push_back("Push");
            result.push_back("Pop");
            j++;
        }
    }

    return result;

}