#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=3e5;
//Implementation of the kosaraju'algorithm for finding the strongly connected components of a directed graph
vector<int>graph[MAXN];
vector<int>transpose[MAXN];
vector<bool>visited(MAXN);
stack<int>vertices;
void dfs1(int start)
{
	 visited[start]=true;
	 for(auto x:graph[start])
	 	if(!visited[x])
	 		dfs1(x);
	 vertices.push(start);
}
void dfs2(int start,vector<int>&component)
{
      component.emplace_back(start);
      visited[start]=true;
      for(auto x:transpose[start])
      	if(!visited[x])
      		dfs2(x,component);
}
signed main()
{
	   int n,m;
	   cin>>n>>m;
	   for(int i=0;i<m;i++)
	   {
	   	     int u,v;
	   	     cin>>u>>v;
	   	     graph[u].emplace_back(v);
	   	     transpose[v].emplace_back(u);
	   }
	   fill(visited.begin(),visited.end(),false);
	   for(int i=0;i<n;i++)
	   {
	   	    if(!visited[i])
	   	    {
	   	    	  dfs1(i);
	   	    }
	   }
	   fill(visited.begin(),visited.end(),false);
	   while(!vertices.empty())
	   {
            int start=vertices.top();
            vertices.pop();
            if(!visited[start])
            {
                vector<int>component;
                dfs2(start,component);
                for(auto x:component)
            	  cout<<x<<" ";
                cout<<endl;
             }
	   }
	   return 0;
}