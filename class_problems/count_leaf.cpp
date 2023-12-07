#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m;
vector<vector<int>> adj;
vector<int> vis;

int dfs(int node){
    vis[node]=1;
    bool is_leaf=true;
    int count_leaf=0;
    for(auto child:adj[node]){
        if(!vis[child]){
            is_leaf=false;
            count_leaf+=dfs(child);
        }
    }
    if(is_leaf) return 1;
    return count_leaf;
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
   cout<<ans<<endl;
}