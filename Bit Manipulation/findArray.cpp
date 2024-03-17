#include<bits/stdc++.h>
using namespace std;

vector<int> findArray(vector<int>& pref) {
    // time/space: O(n)/O(n)
    // vector<int> arr(pref);
    // for(int i=1;i<pref.size();i++){
    //     arr[i]=pref[i-1]^pref[i];
    // }

    // return arr;

    //time/space: O(n)/O(1)
    for(int i=pref.size()-1;i>0;i--){
        pref[i]^=pref[i-1];
    }
    
    return pref;

}