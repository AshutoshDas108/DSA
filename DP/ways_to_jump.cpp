#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int t,n,s;
vector<int> a;

int f(int ind, int src, int dest,vector<vector<int>>& dp){
    if(src==dest) return 1;
    if(ind==n) return src==dest;

    int ans=f(ind+1,src,dest,dp);
    if(src+a[ind]<=dest)
    ans+=f(ind,src+a[ind],dest,dp);

    return ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        a.resize(n);
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<f(0,0,s,dp)<<endl;
    }

}
