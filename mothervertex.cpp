#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=1000000;
int v,e;
vector<int>graph[MAXN];
int potential_mother;
/*If a graph is undirected and connected then obivously every vertex 
will be a mother vertex of the graph*/
/*For a disconnected undirected graph there won't be any mother vertex
as there won't be a vertex connected the two disconnected components*/
/*For a connected graph the mother vertex must be one of the last finished
vertices in the recursion stack of a DFS call*/
void dfs(int start,vector<bool>&visited)
{
	 visited[start]=true;
	 for(auto x:graph[start])
	 {
	 	 if(!visited[x])
	 	 	dfs(x,visited);
	 }
	 return;
}
void dfs_util()
{
	vector<bool>visited(v+1);
	fill(visited.begin(),visited.end(),false);
	for(int i=1;i<=v;i++)
	{
		 if(!visited[i])
		 {
		 	  dfs(i,visited);
		 	  potential_mother=i;
		 }
	}
}
void get_mother_vertex()
{
	dfs_util();
    vector<bool>visited(v+1);
    fill(visited.begin(),visited.end(),false);
    dfs(potential_mother,visited);
    for(int i=1;i<=v;i++)
    {
    	 if(!visited[i])
    	 {
    	 	 cout<<"There is no mother vertex for the given graph "<<endl;
    	 	 return;
    	 }
    }
    cout<<"The mother vertex of the given graph is "<<endl;
    cout<<potential_mother<<endl;
    return;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>v>>e;
	for(int i=1;i<=e;i++)
	{
		 int u,v;
		 cin>>u>>v;
		 graph[u].emplace_back(v);
	}
	get_mother_vertex();
}