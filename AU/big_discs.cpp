#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll t;
ll  x,y,n;
ll  dist (ll x1, ll y1 ,ll  x2,ll  y2){
  return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}

void bfs(ll s,vector<int> adj[], vector<int>& vis){
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
        cin>>x>>y;
        cin>>n;
        vector<vector<int>> l(n,vector<int>(3,0));
         vector<int> adj[n+4];
        for(int i=0;i<n;i++){
            cin>>l[i][0]>>l[i][1]>>l[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              if(dist(l[i][0],l[i][1],l[j][0],l[j][1])<=(l[i][2]+l[j][2])*(l[i][2]+l[j][2])){
                   adj[i+4].push_back(j+4);
                   adj[j+4].push_back(i+4);
              }
            }
        }

        // Left height x coordinate=0
        for(int i=0;i<n;i++){
            if(l[i][0]<=l[i][2]){
                adj[i+4].push_back(0);
                adj[0].push_back(i+4);
            }
        }

        // right height x coordinate=X
        for(int i=0;i<n;i++){
            if(l[i][0]+l[i][2]>=x){
                adj[i+4].push_back(1);
                adj[1].push_back(i+4);
            }
        }

        //upper length y=Y
        for(int i=0;i<n;i++){
            if(l[i][1]+l[i][2]>=y){
                adj[i+4].push_back(2);
                adj[2].push_back(i+4);
            }
        }

        //Lower length y=0;
        for(int i=0;i<n;i++){
            if(l[i][1]<=l[i][2]){
                adj[i+4].push_back(3);
                adj[3].push_back(i+4);
            }
        }

         vector<int> vis0(n+4,0);
         vector<int> vis1(n+4,0);
         vector<int> vis2(n+4,0);
         vector<int> vis3(n+4,0);

         bfs(0,adj,vis0);
         bfs(1,adj,vis1);
         bfs(2,adj,vis2);
         bfs(3,adj,vis3);

          for(int i=0;i<n+4;i++){
            cout<<i<<":->";
            for(auto it: adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }

         if(vis0[2]==1 or vis0[1]==1 or vis1[3]==1 or vis1[0]==1 or vis2[3]==1 or vis2[0]==1
            or vis3[2]==1 and vis3[1]==1){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }

    }
}

