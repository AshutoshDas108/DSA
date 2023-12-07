#include <bits/stdc++.h>
using namespace std;
// BACKWARD PASSING APPROCH
//int max_prof;
int dfs(int node, vector<int>adj[], vector<int>& vis, 
         vector<int>& profits, vector<int>& ans){
          
          vis[node]=1;
          int sum_of_nodes=profits[node-1];
          //bool is_leaf=true;
          //max_prof=INT_MIN;
          for(auto c: adj[node]){
            if(!vis[c]){
              //is_leaf=false;
              sum_of_nodes+=dfs(c,adj,vis,profits,ans);
              //max_prof=max(max_prof,sum_of_nodes);
            }
          }
         
          ans[node]=sum_of_nodes;
          return sum_of_nodes;
         }


int main() {
  int n;
  cin>>n;
  vector<int> adj[n+1];
  int emp[n-1];
  for(int i=0;i<n-1;i++){
    cin>>emp[i];
    adj[emp[i]].push_back(i+2);
  }
  vector<int> profits(n,0);
  for(int i=0;i<n;i++){
    cin>>profits[i];
  }
  if(n==1) cout<<profits[0]<<endl;
  else{
//    for(int i=0;i<n;i++){
//     cout<<profits[i]<<" ";
//   }
//   cout<<endl;
  vector<int> vis(n+1,0);
  vector<int> ans(n+1,0);
  //int max_prof=INT_MIN;
  int x=dfs(1,adj,vis,profits, ans);
  //cout<<max_prof<<" "<<ans;
  //cout<<max_prof<<endl;
  int maxx=INT_MIN;
  for(int i=1;i<=n;i++){
    maxx=max(maxx,ans[i]);
  }
  cout<<maxx<<endl;
  }
  return 0;

}