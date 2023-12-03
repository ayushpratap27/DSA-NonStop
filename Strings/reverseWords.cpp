#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    istringstream iss(s);
    vector<string> words;

    // Extract words from the string
    do {
        string word;
        iss >> word;
        if (!word.empty()) {
            words.push_back(word);
        }
    } while (iss);

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Concatenate the words with a single space
    string result;
    for (const string& word : words) {
        result += word + " ";
    }

    // Remove the trailing space, if any
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}