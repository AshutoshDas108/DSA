#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

bool ok(int x,int y, int n){
       return (x>=0 and x<n and y>=0 and y<n);
   }

   void dfs(int sr, int sc,vector<vector<int>>& grid, vector<vector<int>>& vis,
                queue<pair<int, pair<int,int>>>& q){
        int n=grid.size();
        vis[sr][sc]=1;
        q.push({0,{sr,sc}});
        for(int i=0;i<4;i++){
            int nr=sr+dr[i];
            int nc=sc+dc[i];
            if(ok(nr,nc,n) and vis[nr][nc]==0 and grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,q);
            }
        }
    }

     void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
                queue<pair<int, pair<int,int>>>& q,int& res){
                   bool f=false;
                    int n=grid.size();
                   while(!q.empty()){
                       auto node=q.front();
                       int d=node.first;
                       int r=node.second.first;
                       int c=node.second.second;
                       q.pop();

                       for(int i=0;i<4;i++){
                           int nr=r+dr[i];
                           int nc=c+dc[i];
                           if(ok(nr,nc,n) and vis[nr][nc]==0){
                               vis[nr][nc]=1;
                                if(grid[nr][nc]==1) {
                                f=true;
                                break;
                               }
                               q.push({d+1,{nr,nc}});
                               res=max(res,d+1);
                               cout<<d<<" "<<res<<endl;
                           }
                       }
                       if(f) break;
                   }
                }
        

        int shortestBridge(vector<vector<int>>& grid)
         {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue <pair<int,pair<int,int>>> q;
        bool f=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    f=true;
                   dfs(i,j,grid,vis,q);
                   break;
            }
            }
            if(f) break;
        }
        
        queue <pair<int,pair<int,int>>> q1=q;
            while(!q1.empty()){
              auto it=q1.front();
            cout<<it.first<<" "<<"{"<<it.second.first<<","<<it.second.second<<"}"<<endl;
            q1.pop();
            }

       int res=0;
       bfs(grid,vis,q,res);
       return res;
    }

int main(){
  vector<vector<int>> grid={{0,1,0,0,0},{0,1,0,1,1},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
  int ans=shortestBridge(grid);
  cout<<ans<<endl;
}