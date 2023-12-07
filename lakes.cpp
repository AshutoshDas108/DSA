#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bfs(ll sr, ll sc, vector<vector<ll>>& g,vector<vector<int>>& vis, int delr[], int delc[]){
    vis[sr][sc]=1;
    ll n=g.size();
    ll m=g[0].size();
    ll ans=0;
    queue<pair<ll,ll>> q;
    q.push({sr,sc});
    while(!q.empty()){
      ll r=q.front().first;
      ll c=q.front().second;
      q.pop();
      ans+=g[r][c];
      for(int i=0;i<4;i++){
        ll nr=r+delr[i];
        ll nc=c+delc[i];

        if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==0 and g[nr][nc]!=0){
            vis[nr][nc]=1;
            q.push({nr,nc});
           }
      }
    }
    return ans;
}
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> grid(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll x;
            cin>>x;
            grid[i][j]=x;
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    ll ans=0;
    int delr[4]={-1,1,0,0};
    int delc[4]={0,0,-1,1};
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(vis[i][j]==0 and grid[i][j]!=0){
                ll res=bfs(i,j,grid,vis,delr,delc);
                ans=max(ans,res);
            }
        }
    }
    cout<<ans<<endl;
  }
}