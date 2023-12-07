#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int const m=1e9+7;
int t,n,H;
vector<int> h;

int f(int ind, int height, int H,vector<vector<int>>& dp){
    if(height==H) return 1;
    if(ind==n) return height==H;
    if(dp[ind][height]!=-1) return dp[ind][height];
    int ans=f(ind+1,height,H,dp)%m;
    if(height+h[ind]<=H)
      ans+=f(ind,height+h[ind],H,dp)%m;

    return dp[ind][height]=ans%m;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>H;
        h.resize(n);
        vector<vector<int>> dp(n+1,vector<int>(H+1,-1));
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
       cout<<f(0,0,H,dp)<<endl;
    }
}