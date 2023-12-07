// using the parent

#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m;
vector<int> vis;
vector<vector<int>> adj;
vector<int> ans;
vector<int> par;
int start;
int finish;

void dfs(int x){
    vis[x]=1;
    for(auto c:adj[x]){
        if(!vis[c]){
            par[c]=x;
            dfs(c);
            if(start) return;
        }
        else if(vis[c]==1){
            start=c;
            finish=x;
            return ;
        }
    }
    vis[x]=2;
}

int main(){
    cin>>n>>m;
   adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vis.resize(n+1,0);
    par.resize(n+1,-1);
   // vector<int> cycle;

   for(int i=1;i<=n && !start;i++){
    if(vis[i]==0)
        dfs(i);
   }

   if(!start) {
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
   }

  
       ans.push_back(start);
       int vert=finish;
      // cout<<"aaaa"<<endl;

       while(vert!=start){
        ans.push_back(vert);
        vert=par[vert];
       }
      // cout<<"bbbb"<<endl;
       ans.push_back(start);
       reverse(ans.begin(),ans.end());
       cout<<ans.size()<<endl;
       for(auto it:ans){
        cout<<it<<" ";
       }
       cout<<endl;
}
