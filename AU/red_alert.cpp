#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> adj[], vector<int>& vis, int col[], int C,int cr){
  vis[node]=1;
  
  if(col[node-1]){
    cr++;
      if(cr>C) return 0;
  }
  else{
    cr=0;
  }

  bool is_leaf=true;
  int no_of_leaf=0;
 
  for(auto c:adj[node]){
    if(!vis[c]){
      is_leaf=false;
      no_of_leaf+=dfs(c,adj,vis,col, C, cr);
    }
  }
 
  // else return 0;
  //cout<<node<< " "<< no_of_leaf<<endl;

   if(is_leaf) return 1;

  return no_of_leaf;
}

int main() {
  int n,c;
  cin>>n>>c;
  int col[n];
  for(int i=0;i<n;i++){
    cin>>col[i];
  }
  vector<int> adj[n+1];
  for(int i=1;i<=n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n+1,0);
  //cout<<"-------------------------------------------------------------"<<endl;
  // if(n==1) {
  //   if(col[0]==1 and c>0){
  //     cout<<"0";
  //   }
  //   else{
  //     cout<<"1"<<endl;
  //   }
  // }
  
  int ans=dfs(1,adj,vis, col, c, 0);
  cout<<ans<<endl;
  
  return 0;

}