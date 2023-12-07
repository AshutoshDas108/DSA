  #include<bits/stdc++.h>
  using namespace std;  
    
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    bool safety(int x,int y, int m, int n){
        return (x>=0 and x<m and y>=0 and y<n);
    }

    void bfs(int sr, int sc, int m, int n, vector<string>& g, vector<vector<int>>& d, vector<char>& keys){
          queue<pair<int,int>> q;
          q.push({sr,sc});
          d[sr][sc]=0;

          while(!q.empty()){
              auto f=q.front();
              int r=f.first;
              int c=f.second;
              q.pop();
              for(int i=0;i<4;i++){
                  int nr=r+dr[i];
                  int nc=c+dc[i];
                  if(safety(nr,nc,m,n) and d[nr][nc]==0 and 
                     (g[nr][nc]=='.' or (isalpha(g[nr][nc]) and (g[nr][nc]))  or
                        (isalpha(g[nr][nc]) and isupper(g[nr][nc]))?find(keys.begin(),keys.end(),tolower(g[nr][nc]))!=keys.end():false ))
                      {
                         cout<<nr<<" "<<nc<<endl;
                          d[nr][nc]=d[r][c]+1;
                          if(g[nr][nc]<=122 and g[nr][nc]>=97)
                            keys.push_back(g[nr][nc]);
                          q.push({nr,nc});
                      }
              }
          }
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].length();
        vector<pair<int,int>> keys;
        pair<int,int> start={0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@')
                  {
                      start={i,j};
                  }
                if(isalpha(grid[i][j]) and iswlower(grid[i][j]))
                    keys.push_back({i,j});
            }
        }
        // cout<<start.first<<" "<<start.second<<endl;
        // cout<<keys.size()<<endl;
        // for(int i=0;i<keys.size();i++){
        //     cout<<keys[i].first<<" "<<keys[i].second<<endl;
        // }
        vector<vector<int>> d(m,vector<int>(n,0));
        vector<char> key_values;
       bfs(start.first, start.second,m,m,grid, d,key_values);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<d[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-----------------------------------------"<<endl;
        for(int i=0;i<key_values.size();i++){
            cout<<key_values[i];
        }
        cout<<key_values.size()<<endl;
        if(key_values.size()!=keys.size())  return -1;
        for(auto it:keys){
           // if(d[it.first][it.second]==0) return -1;
            ans=max(ans,d[it.first][it.second]);
        }
        return ans;
    }

    int main(){
        vector<string> g={"@.a..","###.#","b.A.B"};
        cout<<shortestPathAllKeys(g);
    }