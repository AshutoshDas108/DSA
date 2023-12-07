#include <bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int> adj[],int parent,vector<int> &a,int c,int totalc){
    if(a[node]==1)
        c--;
    else
        c=totalc;
    if(c<0)
        return 0;
    int sum=0;
    bool isLeaf=true;
    for(auto it:adj[node]){
        if(it!=parent){
            isLeaf=false;
            sum+=dfs(it,adj,node,a,c,totalc);
        }
    }
    if(isLeaf)
        return 1;
    return sum;
}
int main(){
    int n,c;
    cin>>n>>c;
    vector<int>adj[n];
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    cout<<dfs(0,adj,-1,a,c,c);
}