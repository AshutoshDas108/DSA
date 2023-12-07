#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m;
vector<vector<int>> adj;
vector<int> vis;

int dfs(int node){
    vis[node]=1;
    int max_node=node;
    for(auto c:adj[node]){
        if(!vis[c]){
            max_node=max(max_node,dfs(c));
        }
    }
    return max_node;
}

int main(){
   cin>>n>>m;
   adj.resize(n+1);
   vis.resize(n+1);
   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    //adj[v].push_back(u);
   } 
   int ans=dfs(1);
   cout<<ans;
}