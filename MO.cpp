#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//MO'S Algorithm for handling queries problems in O(sqrt(N)) time
//This is the code for the problem Powerful Array codeforces(Yandex Algorithms 2011-Problem D)
int BLOCK_SIZE;
const int MAXN=2e5+5;
pair<pair<int,int>,int>queries[MAXN];
long long ans[MAXN];
long long current_answer=0;
int freq[MAXN*5];
inline bool compare(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
{
	  int block_a=a.first.first/BLOCK_SIZE;
	  int block_b=b.first.first/BLOCK_SIZE;
	  if(block_a!=block_b)
	  	return block_a<block_b;
	  return a.first.second<b.first.second;
}
inline int add(int x)
{
        current_answer-=1LL*freq[x]*freq[x]*x;
        freq[x]++;
        current_answer+=1LL*freq[x]*freq[x]*x;
}
inline int remove(int x)
{
	 current_answer-=1LL*freq[x]*freq[x]*x;
	 freq[x]--;
	 current_answer+=1LL*freq[x]*freq[x]*x;
}
signed main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int n,q;
	 cin>>n>>q;
	 vector<int>v;
	 for(int i=0;i<n;i++)
	 {
	 	  int x;
	 	  cin>>x;
	 	  v.emplace_back(x);
	 }
	 BLOCK_SIZE=(int)sqrt(n);
	 for(int i=0;i<q;i++)
	 {
	 	   int l,r;
	 	   cin>>l>>r;
	 	   queries[i].first=make_pair(--l,--r);
	 	   queries[i].second=i;
	 }
	 sort(queries,queries+q,compare);
	 int mo_left=0;
	 int mo_right=-1;
	 for(int i=0;i<q;i++)
	 {
	 	   int left=queries[i].first.first;
	 	   int right=queries[i].first.second;
	 	   while(mo_right<right)
	 	   {
	 	   	     mo_right++;
	 	   	     add(v[mo_right]);
	 	   }
	 	   while(mo_right>right)
	 	   {
	 	   	     remove(v[mo_right]);
	 	   	     mo_right--;
	 	   }
	 	   while(mo_left>left)
	 	   {
	 	   	     mo_left--;
	 	   	     add(v[mo_left]);
	 	   }
	 	   while(mo_left<left)
	 	   {
	 	   	     remove(v[mo_left]);
	 	   	     mo_left++;
	 	   }
	 	   ans[queries[i].second]=current_answer;
	 }
	 for(int i=0;i<q;i++)
	 	cout<<ans[i]<<endl;
	 return 0;
}
