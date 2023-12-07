#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

bool dfs(int node, vector<int> adj[], vector<int>& vis,vector<int>& cycle){
         for(auto c:adj[node]){
            vis[node]=1;
            if(vis[c]==0){
                if(dfs(c,adj,vis,cycle)){
                    cycle.push_back(c);
                    // par[c]=node;
                   return true;
                } 
            }
            else if(vis[c]==1) {
                cycle.push_back(c);
                //par[c]=node;
                return true;
            }
         }
         vis[node]=2;
         return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n+1,0);
    //vector<int> par(n+1,-1);
    vector<int> cycle;

    bool ans=false;
    for(int i=1;i<=n;i++){
    ans=dfs(i,adj,vis,cycle);
    if(ans==true) break;
    }
    
    if(ans){
        cycle.push_back(cycle[0]);
        cout<<cycle.size()<<endl;
        for(auto it:cycle){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}