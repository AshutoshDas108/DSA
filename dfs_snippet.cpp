#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs_timer=0;
void dfs(int v,vector<int> adj[],vector<int>& color,vector<int>& time_in, 
        vector<int>&time_out)
         {
    time_in[v] = dfs_timer;
    dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
    {
        if (color[u] == 0)
            dfs(u,adj,color,time_in,time_out);
    }
    color[v] = 2;
    time_out[v] = dfs_timer;
    dfs_timer++;
}

int main(){
   int n=5;
   //cin>>n;
   vector<int> adj[n];
   adj[0]={1,2};
   adj[1]={0,3,4};
   adj[2]={0};
   adj[3]={1};
   adj[4]={1};
   vector<int> color(n);

   vector<int> time_in(n), time_out(n);
   int dfs_timer = 0;

   dfs(0,adj,color,time_in,time_out);
   for(int i=0;i<n;i++){
      cout<<i<<"IN:"<<time_in[i]<<"----OUT:"<<time_out[i]<<endl;
   }
}