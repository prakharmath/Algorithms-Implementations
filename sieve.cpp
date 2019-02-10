#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int>primes;
void sieve(int n)
{
	vector<bool>isprime(n+1);
	for(int i=0;i<=n;i++)
		isprime[i]=true;
	isprime[1]=false;
	for(int i=2;i*i<=n;i++)
	{
		 if(isprime[i])
		 {
		 	 for(int j=2;j*i<=n;j++)
		 	 	isprime[i*j]=false;
		 }
	}
	for(int i=1;i<=n;i++)
	{
		 if(isprime[i])
		 	primes.emplace_back(i);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	sieve(n);
	for(auto x:primes)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}