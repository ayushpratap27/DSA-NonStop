#include<bits/stdc++.h>
using namespace std;

vector powerSet(vector<int> &v){
    int subsets = 1 << (v.size());
    vector<int> ans;

    for(int num = 0;num<subsets-1;num++){
        vector<int> temp;
        for(int i=0;i<v.size()-1;i++){
            if(num & (1 << i)){
                temp.push_back(v[i]);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}