#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void djk(vector<pair<ll,ll>> g[],ll n, ll src, vector<int>& vis,
          vector<ll>& dist){
   vis[src]=0;
   set<pair<ll,ll>> st;
   st.insert({0,src});
   dist[src]=0;
   while(!st.empty()){
    auto it=*(st.begin());
    int node=it.second;
    int len=it.first;
    st.erase(it);

    for(auto it:g[node]){
      int child_node=it.first;
      int len_child=it.second;

      if(len+len_child<dist[child_node]){
        dist[child_node]=len+len_child;
      }
      if(vis[child_node]==0){
        vis[child_node]=1;
        st.insert({dist[child_node],child_node});
      }
    }
   }
}
int main(){
 ll n,m,k;
 cin>>n>>m>>k;
 vector<pair<ll,ll>> graph[n+1];
 for(int i=0;i<m;i++){
    ll u,v,l;
    cin>>u>>v>>l;
    graph[u].push_back({v,l});
    graph[v].push_back({u,l});
 }
 vector<ll> sup;
 if(k>0){
   for (ll i=0;i<k;i++){
   ll city;
   cin>>city;
   sup.push_back(city);
   }
   for(auto it:sup){
    graph[0].push_back({it,0});
   }
 if(n==1){
    cout<<-1<<endl;
 }
 else{
 vector<int> vis(n+1,0);
 vector<ll> dis(n+1,1e9+1);
 djk(graph,n,0,vis,dis);
 ll ans=1e9+5;
 for(int i=0;i<=n;i++){
    if(dis[i]==0 || dis[i]==1e9+1)
    continue;

    ans=min(ans,dis[i]);
 }
 if(ans==1e9+5) cout<<-1<<endl;
 else cout<<ans<<endl;
 }
 }
 else {
    cout<<-1<<endl;
 }
 
}