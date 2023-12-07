#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll n,m,x;
vector<vector<ll>> adj;
vector<vector<ll>> adj1;
vector<int> vis;

void dfs(int  node, vector<int>& d){
   vis[node]=1;
   //d[node]=0;
   for(auto c:adj[node]){
    if(!vis[c]){
        d[c]=d[node]+1;
        dfs(c,d);
    }
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
   int e1,e2;
   vector<int> de1(n+1,0);
   vector<int> de2(n+1,0);

   dfs(1,de1);
   int max_d1=-10;
   for(int i=1;i<=n;i++){
      if(de1[i]>max_d1){
        max_d1=de1[i];
        e1=i;
      }
      cout<<de1[i]<<" ";
   }
   cout<<endl;
   cout<<e1<<endl;
   dfs(e1,de2);
   int max_d2=-10;
   for(int i=1;i<=n;i++){
      if(de2[i]>max_d2){
        max_d2=de2[i];
        e2=i;
      }
      cout<<de2[i]<<" ";
   }
   cout<<endl;
   cout<<e2<<endl;
   cout<<de2[e2]<<endl;
}