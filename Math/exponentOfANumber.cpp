#include <bits/stdc++.h>

// 1LL avoids integer overflow here as it provides long long compatability to no.

int recursive_exp(long long x,long long n, int m)
{
	if(n==0)return 1;
	if(n==1) return x%m;
	if(n==2) return (x*x)%m;
	
	if(n&1)
	return (1LL * (recursive_exp(recursive_exp(x,n/2,m)%m,2,m)%m)*(recursive_exp(x,1,m)%m))%m;
	else
	return (1LL * recursive_exp((recursive_exp(x,n/2,m)%m),2,m)%m);
}


int modularExponentiation(int x, int n, int m) {
	// Write your code here.

	long long lx= x;
	long long ln = n;
	return recursive_exp(lx,ln,m);
}