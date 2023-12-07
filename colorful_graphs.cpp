#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int par,int src,vector<pair<int,int>> g[], vector<int>& c, int n, int& ans,vector<int>& vis){
    vis[src]=1;
    for(auto it:g[src]){
      pair<int,int> p=it;
      int col=p.first;
      int node=p.second;
      if(node==par) continue;
      if(col!=c[par] and node!=par)
        ans++;
        if(vis[node]!=1 and node!=par){
         dfs(par,node,g,c,n,ans,vis);
      }
      
    }
}
int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    vector<pair<int,int>> graph[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(c[u]!=c[v]){
        graph[u].push_back({c[v],v});
        graph[v].push_back({c[u],u});
        }
    }
    for(auto it: graph){
        for(auto it2: it){
            cout<<it2.first<<" "<<it2.second<<" | " ;
        }
        cout<<endl;
    }
    int res=-1,answer=0;
      
    for(int i=1;i<=n;i++){
       int ans=0;
       vector<int> vis(n+1,0);
       dfs(i,i,graph,c,n,ans,vis);
       cout<<ans<<" ";
       if(ans>res){
        res=ans;
        answer=i;
       }
    }
    cout<<endl;
    cout<<answer<<endl;
}