#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int n,m,x;
vector<vector<int>> adj;
vector<int> vis;

int dia=INT_MIN;
int dfs(int node){
    vis[node]=1;
    priority_queue<int> pq;

    for(auto c:adj[node]){
      if(!vis[c]){
        pq.push(dfs(c));
      }
    }
    if(pq.empty()){
        return 1;
    }
    else if(pq.size()==1){
       dia=max(dia,pq.top());
       return pq.top()+1;
    }
    else{
        int f=pq.top();
        pq.pop();
        int s=pq.top();

        dia=max(dia, f+s);
        return f+1;
    }
}

int main(){
   cin>>n;
   adj.resize(n+1);
   vis.resize(n+1);
   for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   } 
   int ans=dfs(1);
   //cout<<ans<<endl;
   cout<<dia;
}