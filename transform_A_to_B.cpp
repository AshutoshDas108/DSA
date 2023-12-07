#include<bits/stdc++.h>
using namespace std;
typedef int ll;


void build_graph(map<ll,vector<ll>>& adj, ll src, ll tar){
   ll levels=0;
   ll x=src;
   while(x<tar){
    x*=2;
    levels++;
   }
   
  // cout<<levels<<endl;

   //size=pow(2,levels)-1;

   queue<ll> q;
   q.push(src);

   while(levels--){
    ll sz=q.size();
    for(ll i=0;i<sz;i++){
        ll s=q.front();
        adj[s]={2*s,10*s+1};
        q.push(2*s);
        q.push(10*s+1);
        q.pop();
    }
   }

   
}


vector<ll> temp;
vector<ll> paths;



void bfs(map<ll, vector<ll>>& adj, ll src, ll dest, map<int,int>& vis){
    queue<vector<ll>> q;
    temp.push_back(src);
    q.push(temp);

    while(!q.empty()){
        temp=q.front();
        q.pop();
        int node=temp.back();

        if(node==dest){
          paths=(temp);
          break;
        }

         for(auto &it:adj[node])
            {
                vector<ll> v(temp);
                v.push_back(it);
                q.push(v);
            }
    }
}

int main(){
    ll src, tar;
    cin>>src>>tar;
    vector<ll> p;
    map<ll, vector<ll>> adj;
    //ll size=0;
    build_graph(adj,src,tar);

     //cout<<size<<endl<<endl;

    // for(auto it:adj){
    //     cout<< it.first<<": ";
    //     for(auto it2: it.second){
    //         cout<<it2<<" ";
    //     }
    //     cout<<endl;
    // }
    map <int,int> vis;
    bfs(adj,src,tar,vis);
    if(paths.size()>0){
        cout<<"YES"<<endl;
        cout<<paths.size()<<endl;
        for(auto it:paths){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}