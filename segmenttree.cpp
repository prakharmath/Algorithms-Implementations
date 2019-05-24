#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=10000000;
/*Implementation of segment tree for range sum queries with updates of a single element*/
/*Segment trees are implement in the style of heaps in the form of arrays so as to simplify
the implementation*/
/*Moreover it can be shown using induction that segment trees require atmost 4*n number of vertices
where n is the number of elemenents in the array*/
/*Therefore segment tree's are an excellent data structure for query based problems as they
support updates as well answering queries both in O(logn) time and they don't consume much 
memory too*/
/*Multi dimensional segment trees can be used to support range queries in multi dimensional 
matrices and more interestingly the time complexity will only be O((logn)**x) where x is the 
dimension for our matrix which is really great*/
vector<int>tree(MAXN);
void build(int vertex,int left,int right,vector<int>v)
{
        if(left==right)
        {
        	 tree[vertex]=v[left];
        	 return;
        }
        int mid=left+(right-left)/2;
        build(2*vertex,left,mid,v);
        build(2*vertex+1,mid+1,right,v);
        tree[vertex]=tree[2*vertex]+tree[2*vertex+1];
}
int query(int vertex,int left,int right,int queryl,int queryr)
{
	if(queryl>queryr)
		return 0;
	if(left==queryl&&right==queryr)
		return tree[vertex];
    int mid=left+(right-left)/2;
    return query(2*vertex,left,mid,queryl,min(queryr,mid))+query(2*vertex+1,mid+1,right,max(queryl,mid+1),queryr);
}
void update(int vertex,int left,int right,int pos,int val)
{
	if(left==right)
	{
		 tree[vertex]=val;
		 return;
	}
	int mid=left+(right-left)/2;
	if(pos<=mid)
	update(2*vertex,left,mid,pos,val);
    else
	update(2*vertex+1,mid+1,right,pos,val);
    tree[vertex]=tree[2*vertex]+tree[2*vertex+1];
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
	build(1,0,n-1,v);
	cout<<query(1,0,n-1,2,5)<<endl;
    update(1,0,n-1,4,123);
    cout<<query(1,0,n-1,2,5)<<endl;
}