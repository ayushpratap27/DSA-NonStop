#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> st;
    
    public:
    Queue() {
    }

    void enQueue(int val) {
        this->st.push(val);
    }

    int deQueue() {
        if(this->st.empty()) return -1;
        stack<int> tmp;
        while(this->st.size()>1){
            tmp.push(st.top());
            st.pop();
        }
        int ans=this->st.top();
        this->st.pop();
        while(!tmp.empty()){
            this->st.push(tmp.top());
            tmp.pop();
        }

        return ans;
    }

    int peek() {
        if(this->st.empty()) return -1;
        stack<int> tmp;
        while(this->st.size()>1){
            tmp.push(st.top());
            st.pop();
        }
        int result=this->st.top();
        while(!tmp.empty()){
            this->st.push(tmp.top());
            tmp.pop();
        }
        return result;
    }

    bool isEmpty() {
        return this->st.empty();
    }
};