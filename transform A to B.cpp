#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int src, int tar, vector<int>& paths){
    if(src>=tar) return;
    paths.push_back(src);

    dfs(2*src,tar,paths);
    dfs(10*src+1,tar,paths);

    paths.pop_back();
}

int main(){
    int src, tar;
    cin>>src>>tar;
    vector<int> paths;
    dfs(src,tar,paths);
    if(paths.size()>0){
        cout<<"YES"<<endl;
        for(auto it:paths){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO";
    }
}


// void dfs(map<ll, vector<ll>>& adj, ll src, 
//             ll dest,map<int,int>& vis)
// {
//     vis[src]=1;
//     temp.push_back(src);
//     if(src==dest) {
//         paths.push_back(temp);
//         temp.pop_back();
//     }

//     else{
//         for(auto x:adj[src]){
//             if(vis.find(x)==vis.end()){
//                 dfs(adj,x,dest,vis);
//             }
//         }
//     }
//     temp.pop_back();
// }