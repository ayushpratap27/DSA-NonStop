#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &target){
    priority_queue<long long> pq;
    long long sum = 0;
    for (int i = 0; i < target.size(); i++){
        pq.push(target[i]);
        sum += target[i];
    }

    long long MaxEle, RemSum, Ele;
    while (pq.top() != 1){
        MaxEle = pq.top();
        pq.pop();
        RemSum = sum - MaxEle;
        if (RemSum <= 0 || RemSum >= MaxEle)
            return 0;

        Ele = MaxEle % RemSum;
        if (Ele == 0){
            if (RemSum != 1){
                return 0;
            }
            else{
                return 1;
            }
        }
        sum = RemSum + Ele;
        pq.push(Ele);
    }

    return 1;
}