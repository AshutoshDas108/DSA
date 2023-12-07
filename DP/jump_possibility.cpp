#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int t,n,s;
vector<int> a;


bool f(int ind, int str, int dest, vector<vector<int>> dp){
    if(str==dest) return true;
    if(ind==n) return str==dest;
    if(dp[ind][str]!=-1) return dp[ind][str];

    bool ans=f(ind+1,str,dest,dp);
    if(a[ind]+str<=dest)
      ans|=f(ind+1,str+a[ind],dest,dp);

    return dp[ind][str]=ans;
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
        bool x=f(0,0,s,dp);
        if(x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
