#include <bits/stdc++.h>
using namespace std;

priority_queue<int> LeftMaxHeap;
priority_queue<int, vector<int>, greater<int>> RightMinHeap;

void insertHeap(int &x){
    if (LeftMaxHeap.empty()){
        LeftMaxHeap.push(x);
        return;
    }
    if (x > LeftMaxHeap.top()){
        RightMinHeap.push(x);
    }
    else{
        LeftMaxHeap.push(x);
    }

    balanceHeaps();
}


void balanceHeaps(){
    if (RightMinHeap.size() > LeftMaxHeap.size()){
        LeftMaxHeap.push(RightMinHeap.top());
        RightMinHeap.pop();
    }
    else{
        if (RightMinHeap.size() < LeftMaxHeap.size() - 1){
            RightMinHeap.push(LeftMaxHeap.top());
            LeftMaxHeap.pop();
        }
    }
}

double getMedian(){
    if (LeftMaxHeap.size() > RightMinHeap.size()){
        return LeftMaxHeap.top();
    }
    else{
        double ans = LeftMaxHeap.top() + RightMinHeap.top();
        ans /= 2;
        return ans;
    }
}