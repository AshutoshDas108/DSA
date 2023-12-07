#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
//std::vector<ll> a;
ll m=1e9+7;

ll f(ll score, vector<vector<ll>>& dp,int _4){
   if(score==n) return 1;
   if(dp[score][_4]!=-1) return dp[score][_4];

   ll ans=f(score+1,dp,0)%m;
   if(score+2<=n) ans+=f(score+2,dp,0)%m;
   if(score+4<=n and _4!=1) ans+=f(score+4,dp,1)%m;
   if(score+6<=n) ans+=f(score+6,dp,0)%m;
   return dp[score][_4]=ans%m;
}

ll f_2(){
    //dp[i][1]--> i runs were scored and previous shot was a 4
    //dp[i][0]--> i runs were scored and previous shot not was a 4
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        if(i-2>=0) dp[i][0]+=dp[i-2][0]+dp[i-2][1];
        if(i-6>=0) dp[i][0]+=dp[i-6][0]+dp[i-6][1];

        dp[i][1]=dp[i-4][0];
    }
    return dp[n][0]+dp[n][1];
}

int main()
{   
        cin>>n;
        vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
        cout<<f(0,dp,0)<<endl;
        cout<<f_2()<<endl;
}