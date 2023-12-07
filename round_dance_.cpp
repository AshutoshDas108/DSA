#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(set<ll> adj[], ll n, ll start, vector<int>& vis){
   vis[start]=1;
   queue<ll> q;
   q.push(start);
   while(!q.empty()){
     ll f=q.front();
     q.pop();

     for(auto it:adj[f]){
        if(!vis[it]){
            vis[it]=1;
            q.push(it);
        }
     }
   }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==2){
            cout<<1<<endl;
        }
        else
        {
        set<ll> adj[n+1];
        for(ll i=0;i<n;i++){
          adj[i+1].insert(a[i]);
          adj[a[i]].insert(i+1);
        }
        ll count_deg=0;
        for(auto it:adj){
            if(it.size()==1){
                count_deg++;
            }
            // for(auto it2=it.begin();it2!=it.end();it2++){
            //     cout<<*it2<<" ";
            // }
            // cout<<endl;
        }
        ll count_comp=0;
        vector<int> vis(n+1,0);
        for(ll i=1;i<=n;i++){
           if(vis[i]==0){
            count_comp++;
            bfs(adj,n,i,vis);
           }
        }
        
        if(count_comp==1){
            cout<<1<<" "<<1<<endl;
        }
        else if(count_deg==0){
            cout<<count_comp<<" "<<count_comp<<endl;
        }
        else if((count_deg/2)>=(count_comp)) {
            cout<<1<<" "<<count_comp<<endl;
        }
        else if((count_deg/2)<(count_comp)){
           ll minsz=count_comp-(count_deg/2)+1;
           ll maxsz=count_comp;
           cout<< minsz <<" "<<maxsz<<endl;
        }
        }
    }
}
