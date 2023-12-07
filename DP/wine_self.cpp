#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
vector<vector<int>> dp;


int solve(int i, int j, int n, int p[]){
    if(i==j) return n*p[i];
    if(dp[i][j]!=-1) return dp[i][j];
    int y=n-(j-i);
    int ans=max((solve(i+1,j,n,p)+y*p[i]), (solve(i,j-1,n,p)+y*p[j]));
    return dp[i][j]=ans;
}

int main(){
   int n;
   cin>>n;
   dp.resize(n+1,vector<int>(n+1,-1));
   int p[n];
   for(int i=0;i<n;i++){
    cin>>p[i];
   }
  cout<< solve(0,n-1,n,p);
}

