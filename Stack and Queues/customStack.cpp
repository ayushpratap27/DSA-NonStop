#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if(stack.size() < maxSize){
            stack.push_back(x);
        }
    }

    int pop() {
        if(stack.empty()){
            return -1;
        }
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    void increment(int k, int val) {
        int n = stack.size();
        int limit = min(k, n);
        for(int i=0;i<limit;i++){
            stack[i] += val;
        }
    }
};

