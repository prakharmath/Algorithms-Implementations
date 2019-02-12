#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int gcd(vector<int>&v)
{
	 int res=0;
	 for(auto x:v)
	 	res=__gcd(res,x);
	 return res;
}
int lcm(vector<int>&v)
{
	int res=v[0];
	for(int i=1;i<(int)v.size();i++)
	{
		 res=(res*v[i])/(__gcd(res,v[i]));
	}
	return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++)
	{
		 int x;
		 cin>>x;
		 v.emplace_back(x);
	}
	cout<<"The gcd of the array is "<<gcd(v)<<endl;
	cout<<"The lcm of the array is "<<lcm(v)<<endl;
}