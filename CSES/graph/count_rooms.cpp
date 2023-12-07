#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




void bfs(int sr, int sc,vector<vector<char>>& b, vector<vector<int>>& vis
                  , int dr[], int dc[])
                  {
                    int m=b.size();
                    int n=b[0].size();
                    queue<pair<int,int>> q;
                    q.push({sr,sc});
                    vis[sr][sc]=2;

                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();

                        for(int i=0;i<4;i++){
                            int nr=r+dr[i];
                            int nc=c+dc[i];
                            if(nr>=0 and nr<n and nc>=0 and nc<m and vis[nr][nc]==-1)
                            {
                                vis[nr][nc]=2;
                                q.push({nr,nc});
                            }
                        }
                    }

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> building(n,vector<char>(m,' '));
    vector<vector<int>> vis(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='#')
              vis[i][j]=1;

            building[i][j]=ch;
        }
    }
   
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    int no_of_rooms=0;

for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<building[i][j]<<" ";
        }
        cout<<endl;
}

for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
}

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==-1)
            {
                bfs(i,j,building,vis,dr,dc);
                no_of_rooms++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
}

cout<<endl;
   // cout<<m<<" "<<n<<endl;
    cout<<no_of_rooms<<endl;
}
