#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m;
vector<vector<int>> adj;
vector<int> vis;

pair<int,int> dfs(int node){
    vis[node]=1;
    int take=node;
    int not_take=0;
    for(auto c:adj[node]){
        if(!vis[c]){
            take+=dfs(c).second;
            not_take+=max(dfs(c).first,dfs(c).second);
        }
    }
    return {take,not_take};
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
   pair<int,int> ans=dfs(1);
 cout<< max(ans.first,ans.second);
}