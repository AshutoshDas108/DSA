#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> adj[], vector<int>& d, vector<int>& par){
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int f=q.front();
        q.pop();
        d[src]=0;
        par[src]=0;
        for(auto c:adj[f]){
            if(d[c]==-1){
                d[c]=d[f]+1;
                par[c]=f;
                q.push(c);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    // N nodes numbered 1 to n
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d(n+1,-1);
    vector<int> par(n+1,-1);
    bfs(1, adj , d, par);
    if(d[n]!=-1){
        cout<<d[n]<<endl;
        int x=n;
        vector<int> p;
        while(par[x]!=0){
           p.push_back(x);
           x=par[x];
        }
        p.push_back(1);
        reverse(p.begin(),p.end());
        for(auto it:p){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NOT RECHABLE"<<endl;
    }
}