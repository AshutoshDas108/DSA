#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m,x;
vector<vector<int>> adj;
vector<int> vis;

int dfs(int node){
    vis[node]=1;
    bool is_leaf=true;
    int sum_leaf=0;
    for(auto c:adj[node]){
        if(!vis[c]){
            is_leaf=false;
             sum_leaf+=dfs(c);
        }
    }
    if(is_leaf){
       return node;
    }
    return sum_leaf-(sum_leaf/10);
}

int main(){
   cin>>n>>x;
   adj.resize(n+1);
   vis.resize(n+1);
   for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    //adj[v].push_back(u);
   } 
   int ans=dfs(1);
   //cout<<ans<<endl;
   if(ans>=x) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}