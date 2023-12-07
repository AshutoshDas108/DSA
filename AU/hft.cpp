#include <bits/stdc++.h>
using namespace std;

int max_prof;
int dfs(int node, vector<int>adj[], vector<int>& vis, 
         vector<int>& profits){
          
          vis[node]=1;
          int sum_of_nodes=0;
          bool is_leaf=true;
          max_prof=INT_MIN;
          for(auto c: adj[node]){
            if(!vis[c]){
              is_leaf=false;
              sum_of_nodes+=dfs(c,adj,vis,profits);
              max_prof=max(max_prof,sum_of_nodes);
            }
          }
          if(is_leaf) return profits[node-1];

          //cout<<node<<" "<<sum_of_nodes<<endl;

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
  //int max_prof=INT_MIN;
  int ans=dfs(1,adj,vis,profits);
  //cout<<max_prof<<" "<<ans;
  cout<<max_prof<<endl;
  }
  return 0;

}