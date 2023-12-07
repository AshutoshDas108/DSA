#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll n,m,x;
vector<vector<pair<ll,ll>>> adj;
vector<int> vis;

ll dfs(ll node){
   vis[node]=1;
   ll cost=0;
   for(auto c:adj[node]){
    if(!vis[c.second]){
       cost+=dfs(c.second);
    }
   }
   return cost;
}

int main(){
   cin>>n>>x;
   adj.resize(n+1);
   vis.resize(n+1);
   for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back({0,v});
    adj[v].push_back({x,u});
   } 
   cout<<dfs(1)<<endl;
}