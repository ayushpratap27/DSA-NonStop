#include<bits/stdc++.h>
using namespace std;

int secondHighest(string s) {
    vector<int> digits;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            int temp = s[i]-'0';
            digits.push_back(temp);
        }
    }
    if(digits.size() <= 1){
        return -1;
    }
        
    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < digits.size(); i++){
        if(digits[i] > firstLargest){
            secondLargest = firstLargest;
            firstLargest = digits[i];
        }else if(digits[i] > secondLargest && digits[i] < firstLargest){
            secondLargest = digits[i];
        }
    }

    if(secondLargest == INT_MIN){
        return -1;
    }


    return secondLargest;
}