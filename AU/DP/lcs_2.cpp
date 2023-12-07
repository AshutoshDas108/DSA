#include <bits/stdc++.h>
using namespace std;
string s,t;
string res=" ";

int f(int i1, int i2, vector<vector<int>>& dp){
  if(i1==0 or i2==0) return 0;
  if(dp[i1][i2]!=-1) return dp[i1][i2];
  int ans=0;
  if(s[i1-1]==t[i2-1]){
    res=res+s[i1-1];
    ans=1+f(i1-1,i2-1,dp);
  }
  else{
    ans=max(f(i1-1,i2,dp), f(i1,i2-1,dp));
  }
  return dp[i1][i2]=ans;
}
int main() {
 cin>>s>>t;
 vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
 cout<<f(s.length(), t.length(), dp)<<endl;
 reverse(res.begin(), res.end());
 cout<<res;
  return 0;

}