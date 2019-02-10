#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int power(int x,int y,int p)
{
	 int res=1;
	 while(y>0)
	 {
	 	 if(y&1)
	 	 {
	 	 	 res*=x;
	 	 	 res%=p;
	 	 }
	 	 x=(x*x)%p;
	 	 y/=2;
	 }
	 return res;
}
int inverse(int x,int p)
{
	 return power(x,p-2,p);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x,y,p;
	cin>>x>>y>>p;
	cout<<power(x,y,p)<<endl;
}