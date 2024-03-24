#include<bits/stdc++.h>
using namespace std;

# define ll long long int
class MinStack {
public:
    stack<ll> st;
    ll mini;
    MinStack() {
        this->mini=INT_MAX;
    }
    
    void push(int val) {
        if(this->st.empty()){
            this->mini=val;
            this->st.push(val);
        }else{
            this->st.push(val - this->mini);
            if(this->mini > val){
                this->mini=val;
            }
        }
    }
    
    void pop() {
        if(!this->st.empty()){
            if(this->st.top()>=0){
                this->st.pop();
            }else{
                this->mini=this->mini - this->st.top();
                this->st.pop();
            }
        }
    }
    
    int top() {
        if(this->st.size()==1){
            return this->st.top();
        }else if(this->st.top()<0){
            return this->mini;
        }else{
            return this->mini + this->st.top();
        }
    }
    
    int getMin() {
        return this->mini;
    }
};

