#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> v) {
	// Write your code here
	int n=v.size();
	int max=-1;
	vector<int> freq(max+1,0);

	for(int i=0;i<n;i++){
		if(v[i]>max){
			max=v[i];
		}
	}
	for(int i=0;i<n;i++){
		freq[v[i]]++;
	}
	for(int i=0;i<freq.size();i++){
		if(freq[i]>(n/2)){
			return i;
		}
	}

}

int main(){
    int t;
    cin>>t;

    while(t--){
        

    }  
   
}

int majorityElement(vector<int> v) {
    int n = v.size();
    int candidate = v[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = v[i];
            count = 1;
        }
    }

    // At this point, 'candidate' holds a potential majority element
    // Check if it occurs more than n/2 times
    count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        // If no majority element is found, you can return a specific value or handle it as needed.
        // For example, you can return -1 or throw an exception.
        return -1;
    }
}
