#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
//Works in O(sqrt(n)) time , for multiple queries use sieve*/
void factorise(int n,vector<int>&v)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		 if(n%i==0)
		 {
		 	 while(n%i==0)
		 	 {
		 	 	 v.emplace_back(i);
                 n/=i;
		 	 }
		 }
	}
	if(n>=2)
		v.emplace_back(n);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
    vector<int>v;
    factorise(n,v);
    cout<<"The prime factorisation of given number is "<<endl;
    for(auto x:v)
    	cout<<x<<" ";
    cout<<endl;
    return 0;
}