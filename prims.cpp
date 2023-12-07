#include <bits/stdc++.h>
using namespace std;

int prims(vector<pair<int,int>> adj[], int V, vector<pair<int,int>>& mst){
   vector<int> vis(V,0);
   priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
   pq.push({0,0,-1});
   vis[0]=1;
   int mst_wt=0;

   while(!pq.empty()){
    vector<int> v=pq.top();
    pq.pop();

    int ed_wt=v[0];
    int node=v[1];
    int parent=v[2];

    if(vis[node]==1) continue;

    vis[node]=1;
    mst_wt+=ed_wt;
    if(parent!=-1){
        mst.push_back({parent,node});
    }

    for(auto it: adj[node]){
        int next_node=it.first;
        int wt=it.second;
        if(vis[next_node]==0){
            pq.push({wt,next_node,node});
        }
    }
   }
   return mst_wt;
}

int main(){
    vector<vector<int>>edges ={{0,1,2},{0,2,1},{1,2,1},{2,3,2},{3,4,1},{4,2,2}};
    vector<pair<int,int>> adj[5];
    for(int i=0;i<edges.size();i++){
        vector<int> t=edges[i];
        adj[t[0]].push_back({t[1],t[2]});
        adj[t[1]].push_back({t[0],t[2]});
    }
   
    vector<pair<int,int>> MST;

     int weight_of_mst= prims(adj,5,MST);
    cout<<"Weight of MST="<<weight_of_mst<<endl;
    cout<<"The edges constituting the MST are:"<<endl;
    for(auto it:MST){
        cout<<it.second<<"<-->"<<it.first<<endl;
    }
}
