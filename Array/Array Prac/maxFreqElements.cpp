#include<bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
      vector<int> freq(101,0);
      int maxi = 0, count = 0;
      for(int x: nums){
          freq[x]++;
          count+=(freq[x]==maxi);

          if(freq[x]>maxi) count=1, maxi=freq[x];
      }

       return count*maxi;
}
