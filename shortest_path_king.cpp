#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(int sr, int sc, vector<vector<int>>& vis, vector<vector<int>>& dist, vector<string>& moves){
    vis[sr][sc]=1;
    queue<pair<int,int>> q;
    q.push({sr,sc});
    dist[sr][sc]=0;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nr=r+i;
                int nc=c+j;
                if(nr>=0 and nr<=8 and nc>=0 and nc<=8){
                    if(dist[nr][nc]>dist[r][c]+1){
                        dist[nr][nc]=dist[r][c]+1;
                    }
                }
            }
        }
    }
}
int main(){
    string s,t;
    cin>>s>>t;
    int const A=65;
    int sr=(isdigit(s[0])?(int)s[0]:(int)(s[0]%A + '0'));
    int sc=int(s[1]);
    int tr=(isdigit(s[0])?(int)s[0]:(int)(s[0]%A + '0'));
    int tc=(int)t[1];
    vector<string> moves;
    vector<vector<int>> vis(9,vector<int>(9,0));
    vector<vector<int>> dist(9,vector<int>(9,1e9+1));
}