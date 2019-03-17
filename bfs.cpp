#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int>graph[200000];
/*bfs for a directed and disconnected graph*/
/*It also calculates the number of connected components in the graph*/
void bfsfrom(int start,vector<bool>&visited)
{
	queue<int>q;
	visited[start]=true;
	q.push(start);
	while(!q.empty())
	{
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto y:graph[x])
        {
        	 if(!visited[y])
        	 {
        	 	visited[y]=true;
        	 	q.push(y);
        	 }
        }
	}
	cout<<endl;
}
void bfs(int v)
{
    vector<bool>visited;
	visited.resize(v+1);
	fill(visited.begin(),visited.end(),false);
	int connected_components=0;
	for(int i=1;i<=v;i++)
	{
		 if(!visited[i])
		 {
		 	 bfsfrom(i,visited);
		 	 connected_components++;
		 }
	}
	cout<<endl;
	cout<<"The number of connected components in the given graph are ";
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
	  bfs(v);
}
