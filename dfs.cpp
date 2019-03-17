#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=1000000;
vector<int>graph[MAXN];
/*DFS for a directed graph*/
/*Also calculates the number of connected components in the graph*/
void dfs(int start,vector<bool>&visited)
{
	 visited[start]=true;
	 cout<<start<<" ";
	 for(auto x:graph[start])
	 {
	 	   if(!visited[x])
	 	   	dfs(x,visited);
	 }
	 return;
}
void dfs_from(int start,int vertices)
{
	 vector<bool>visited(vertices+1);
	 fill(visited.begin(),visited.end(),false);
	 int connected_components=0;
	 cout<<"The DFS Traversal of the given graph is "<<endl;
	 for(int i=1;i<=vertices;i++)
	 {
	 	 if(!visited[i])
	 	 {
	 	 	  dfs(i,visited);
	 	 	  connected_components++;
	 	 }
	 }
	 cout<<endl;
	 cout<<"The number of connected components in the graph are ";
	 cout<<connected_components<<endl;
	 return;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		 int u,v;
		 cin>>u>>v;
		 graph[u].emplace_back(v);
		 graph[v].emplace_back(u);
	}
	dfs_from(1,v);
}
