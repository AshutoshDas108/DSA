#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int node, int lvl){
    vis[node]=1;
    cout<<node<<" "<<lvl<<endl;
    for(auto c:adj[node]){
        if(!vis[c]){
            dfs(c,lvl+1);
        }
    }
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
  dfs(1,0);
}