#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m;
vector<int> vis;
vector<vector<int>> adj;
vector<int> ans;

bool dfs(int x){
    vis[x]=1;
    for(auto c:adj[x]){
        if(!vis[c]){
        if(dfs(c)) return true;
        }
        else if(vis[c]==1) return true;
    }
    vis[x]=2;
    ans.push_back(x);
    return false;
}

int main(){
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vis.resize(n+1);

    bool f=false;
    for(int i=1;i<=n;i++){
        if(vis[i]==0)
        f=dfs(i);

        if(f) break;
    }
    if(f) cout<<"IMPOSSIBLE"<<endl;
    else{
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
    }
}