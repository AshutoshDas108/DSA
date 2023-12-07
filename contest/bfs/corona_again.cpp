#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;


int n,m;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
vector<vector<char>> g;
vector<vector<char>> grid;
vector<vector<int>> vis;

bool ok(int nr, int nc){

    if(nr<n and nr>=0 and nc<m and nc>=0)
    return true;

    return false;
}

bool F=false;
void bfs(int tr, int tc, queue<pair<int, pair<int,int>>>& q, vector<vector<char>>& g, vector<vector<int>>& d){
         while(!q.empty())
        {
           auto f=q.front();
           int col=f.first;
           int r=f.second.first;
           int c=f.second.second;

           q.pop();
           for(int i=0;i<4;i++)
           {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(ok(nr,nc) and d[nr][nc]==0)
            {
                d[nr][nc]=col;
                if(nr==tr and nc==tc){
                    F=true;
                    break;
                } 
                q.push({col,{nr,nc}});
            }
           }
           if(F) break;
        }
}

int main()
{
    cin>>n>>m;
    g.resize(n,vector<char>(m,' '));
    grid.resize(n,vector<char>(m,' '));
    pair<int,int> src;
    pair<int,int> dest;
    vector<pair<int,int>> dengers;
    vis.resize(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           char ch;
           cin>>ch;
           grid[i][j]=ch;
           if(ch=='#') vis[i][j]=1;
           if(ch=='s'){
             src={i,j};
             ch='*';
           }
           if(ch=='h') {
            dest={i,j};
            ch='*';
           }
           if(ch=='d'){
            dengers.push_back({i,j});
            ch='*';
           }
           g[i][j]=ch;
        }
    }

    queue<pair<int,pair<int,int>>> q;
    for(auto it:dengers){
        q.push({-2,it});
        vis[it.first][it.second]=-2;
    }
    q.push({2,src});
    vis[src.first][src.second]=2;

     bfs(dest.first,dest.second,q,g,vis);

    if(vis[dest.first][dest.second]==2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}