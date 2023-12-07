#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;


int n,m,k;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
vector<vector<char>> g;
vector<vector<int>> vis;

bool ok(int nr, int nc){

    if(nr<n and nr>=0 and nc<m and nc>=0)
    return true;

    return false;
}

bool F=false;
void bfs(int sr, int sc, int tr, int tc, vector<vector<char>>& g, vector<vector<int>>& d)
      {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        d[sr][sc]=0;

        while(!q.empty())
        {
           pair<int,int> f=q.front();
           int r=f.first;
           int c=f.second;

           q.pop();
           for(int i=0;i<4;i++)
           {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(ok(nr,nc) and d[nr][nc]==-1)
            {
                d[nr][nc]=d[r][c]+1;
                if(nr==tr and nc==tc){
                    F=true;
                    break;
                } 
                q.push({nr,nc});
            }
           }
           if(F) break;
        }
      }

int main()
{
    cin>>n>>m>>k;
    g.resize(n,vector<char>(m,' '));
    pair<int,int> src;
    pair<int,int> dest;
    vis.resize(n,vector<int>(m,-1));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           char ch;
           cin>>ch;
           if(ch=='#') vis[i][j]=true;
           if(ch=='i'){
             src={i,j};
             ch='*';
           }
           if(ch=='h') {
            dest={i,j};
            ch='*';
           }
           g[i][j]=ch;
        }
    }
    bfs(src.first,src.second,dest.first,dest.second,g,vis);
    if(!F) cout<<"NO"<<endl;
    else {
        if(vis[dest.first][dest.second]<=k)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
  return 0;
}