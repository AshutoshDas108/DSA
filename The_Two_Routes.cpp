#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(int src, vector<int> adj[], vector<int> vis, vector<int> & dist)
{
    queue<int> q;
    q.push(src);
    vis[src]=1;
    dist[src]=0;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(auto x:adj[f])
        {
            if(vis[x]==0)
            {
                vis[x]=1;
                q.push(x);
                dist[x]=dist[f]+1;
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(m,vector<int>(2,0));
    vector<vector<int>> paths(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        cin>>e[i][0]>>e[i][1];
        paths[e[i][0]][e[i][1]]=1;
        paths[e[i][1]][e[i][0]]=1;
    }

    vector<int> road[n+1];
    vector<int> rail[n+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
          if(i!=j)
          {
           if(paths[i][j]==1)
           {

            rail[i].push_back(j);
            rail[j].push_back(i);

           }
           else
           {

             road[i].push_back(j);
             road[j].push_back(i);
    
           }
        }
        }
    }

    vector<int> dist_road(n+1,-1);
    vector<int> dist_rail(n+1,-1);

    vector<int> vis(n+1,0);

    bfs(1,road,vis,dist_road);
    bfs(1,rail,vis,dist_rail);

    if(min(dist_rail[n],dist_road[n])==-1) cout<<-1<<endl;
    else cout<< max(dist_rail[n],dist_road[n]) << endl;
    
}