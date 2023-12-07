#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(vector<ll> g[], ll s , ll t, vector<int>& vis, bool& ans){
   vis[s]=1;
   for(auto it:g[s]){
    if(it==t) {
        ans=true;
        return;
    }
    else{
    if(!vis[it]){
         dfs(g,it,t,vis,ans);
    }
    }
   }
}
int main(){
    ll n,t;
    cin>>n>>t;
    ll a[n-1];
    for(ll i=0;i<n-1;i++){
        cin>>a[i];
    }
    vector <ll> adj[n];
    for(ll i=0;i<n-1;i++){
        adj[i+1].push_back(i+1+a[i]);
    }
       if(n==1)
       {
           cout<<"YES"<<endl;;
       }
      else if(t==1)
       {
          cout<<"YES"<<endl;
       }
       else{
    vector<int> vis(n,0);
    bool f=false;
    dfs(adj,1,t,vis,f);
    if(f){
        cout<<"YES"<<endl;
    }     
    else{
        cout<<"NO"<<endl;
    }
       }
}