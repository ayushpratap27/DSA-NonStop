#include <bits/stdc++.h> 
using namespace std;

const int mod = 1000000007;
long long int sumOrProduct(long long int n, long long int q)
{
	long long sum=(n*(n+1))/2;
	long long product=1;
	if(q==1) {
		return sum;
	} else {
		for(long long i=1;i<=n; i++) {
			product=((product%mod)*i)%mod;
		}
		return product;
	}
}