#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;


int t;
int m,n;

int dist(int x1, int y1, int x2, int y2){
return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}

void bfs(int s,vector<int> adj[], vector<int>& vis){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    
    while(!q.empty()){
        int f=q.front();
        q.pop();

        for(auto c:adj[f]){
            if(vis[c]==0){
                vis[c]=1;
                q.push(c);
            }
        }
    }
}

int main(){
    cin>>t;
    while(t--){
        cin>>m>>n;
       vector<int> adj[n+2];
       vector<vector<int>> l(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
           cin>>l[i][0]>>l[i][1]>>l[i][2];
        }
        vector<int> vis(n+2,0);
        vector<int> vis1(n+2,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              if(dist(l[i][0],l[i][1],l[j][0],l[j][1])<=(l[i][2]+l[j][2])*(l[i][2]+l[j][2])){
                   adj[i+1].push_back(j+1);
                   adj[j+1].push_back(i+1);
              }
            }
        }
        for(int i=0;i<n;i++){
            if(l[i][0]<=l[i][2]){
                adj[i+1].push_back(0);
                adj[0].push_back(i+1);
            }
        }
         for(int i=0;i<n;i++){
            if(l[i][0]+l[i][2]>=m){
                adj[i+1].push_back(n+1);
                adj[n+1].push_back(i+1);
            }
        }
         
        for(int i=0;i<n+2;i++){
            cout<<i<<":->";
            for(auto it: adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
 
        bfs(0,adj,vis);
        bfs(n+1,adj,vis1);
        if(vis[n+1]==1 || vis1[0]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}