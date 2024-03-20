#include <bits/stdc++.h>
using namespace std;


stack<int> sortStack(stack<int> &s)
{
	// Write code here.
	int n=s.size();
	vector<int> v;
	for(int i=0;i<n;i++){
		v.push_back(s.top());
		s.pop();
	}
	sort(v.begin(),v.end());
	stack<int> st;
	for(int i=0;i<n;i++){
		st.push(v[i]);
	}

	return st;
}