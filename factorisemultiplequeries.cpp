#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=10000000;
vector<int>spf(MAXN+1);
/*This is modified sieve which is used for getting factorisation of a number in O(logn) but is 
mostly used for multiple queries regarding factorisation. Works well for order 10**7 . After
That it will face memory issues*/
/*Idea is based on getting the smallest prime factor of an integer and then using memoization 
to store the data*/
void sieve()
{
	for(int i=1;i<=MAXN;i++)
	{
		 if(i&1)
		 	spf[i]=i;
		 else
		 	spf[i]=2;
	}
	for(int i=3;i*i<=MAXN;i++)
	{
		 if(spf[i]==i)
		 {
		 	 for(int j=i*i;j<=MAXN;j+=i)
		 	 {
		 	 	  if(spf[j]==j)
		 	 	  	spf[j]=i;
		 	 }
		 }
	}
}
vector<int>getfactorisation(int n)
{
	 vector<int>res;
	 while(n!=1)
	 {
	      res.emplace_back(spf[n]);
	      n/=spf[n];
	 }
	 return res;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	int q;
	cin>>q;
	while(q--)
	{
		 int n;
		 cin>>n;
		 vector<int>res=getfactorisation(n);
		 for(auto x:res)
		 	cout<<x<<" ";
		 cout<<endl;
	}
	return 0;
}