#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

void bfs(int src, vector<int> adj[], vector<int>& d){
    queue<int> q;
    q.push(src);
    d[src]=0;

    while(!q.empty()){
        int f=q.front();
        q.pop();

        for(auto c: adj[f]){
            if(d[c]==0){
                d[c]=d[f]+1;
                q.push(c);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> ds(n+1,0);
    vector<int> dt(n+1,0);
    bfs(1,adj,ds);
    bfs(n,adj,dt);
    int sd=ds[n];
    
    if(sd==0) cout<<"-1"<<endl;
    else{
    cout<<1<<" ";
    for(int i=1;i<=n;i++){
       if(ds[i]+dt[i]==sd){
        cout<<i<<" ";
       }
    }
    cout<<n<<" ";
    cout<<endl;
    }
}