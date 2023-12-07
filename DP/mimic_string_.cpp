#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int T,n,m;
string s,t;

int f(int i, int j,vector<vector<int>>& dp){
    if(i==0) return j;
    if(j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
     int ans=INT_MAX;
     if(s[i-1]==t[j-1])
      ans = 0 + f(i-1,j-1,dp);
     else
      ans = 1 + min({f(i-1,j,dp) ,f(i,j-1,dp), f(i-1,j-1,dp)});

     return dp[i][j]=ans;
}

int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        cin>>s>>t;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        if(s==t) cout<<0<<endl;
        else
        cout<<f(n,m,dp)<<endl;
    }
}