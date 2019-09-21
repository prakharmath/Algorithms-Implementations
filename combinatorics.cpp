#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
//Code to calculate factorials ,Inverse factorials and binomial coefficients
const int MAXN=1e6;
const int MOD=1e9+7;
int fact[MAXN+5];
int inv_fact[MAXN+5];
int power(int x,int y,int p)
{
	   int res=1;
	   while(y>0)
	   {
	   	    if(y&1)
	   	    	res=(res%MOD*x%MOD)%MOD;
	   	    y>>=1;
	   	    x=(x%MOD*x%MOD)%MOD;
	   }
	   return res;
}
int inverse(int x)
{
	  assert(__gcd(x,MOD)==1);
	  return power(x,MOD-2,MOD);
}
void pre()
{
	  fact[0]=1;
	  inv_fact[0]=inverse(fact[0]);
	  for(int i=1;i<=MAXN;i++)
	  {
	  	    fact[i]=(i*fact[i-1])%MOD;
	  	    inv_fact[i]=inverse(fact[i]);
	  }
}
signed main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 pre();
	 int n,r;
	 cin>>n>>r;
	 int res=1;
	 res*=fact[n];
	 res%=MOD;
	 res*=inv_fact[r];
	 res%=MOD;
	 res*=inv_fact[n-r];
	 res%=MOD;
	 cout<<res<<endl;
	 return 0;
}
