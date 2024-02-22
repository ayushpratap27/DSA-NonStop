#include <bits/stdc++.h>
using namespace std;

int countWords(string input) {
    int cnt=0;
    for(int i=0;i<input.size();i++){
        if(input[i]==' '){
            cnt++;
        }
    }

    return cnt+1;
}

int main() {
    string input;
    getline(cin, input);
    int output = countWords(input);
    cout << output << endl;
    return 0;
}