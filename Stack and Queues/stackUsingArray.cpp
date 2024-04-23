#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
    int capacity; 
    vector<int> data; 

public:
    Stack(int capacity) {
        this->capacity = capacity;
    }

    void push(int num) {
        if (data.size() < capacity) {
            data.push_back(num);
        }
    }

    int pop() {
        if (!isEmpty()) {
            int topElement = data.back();
            data.pop_back();
            return topElement;
        } else {
            return -1;
        }
    }

    int top() {
        if (!isEmpty()) {
            return data.back();
        } else {
            return -1;
        }
    }

    int isEmpty() {
        return data.empty() ? 1 : 0;
    }

    int isFull() {
        return (data.size() == capacity) ? 1 : 0;
    }
};
