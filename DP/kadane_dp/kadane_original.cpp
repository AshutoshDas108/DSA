#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll n;
vector<ll> a;

ll f(ll ind, vector<ll>& dp){
   dp[0]=a[0];
   for(int i=1;i<n;i++){
    dp[i]=max({dp[i-1]+a[i], a[i]});
   }
   return max(dp[n-2],dp[n-1]);
}

ll f_optm(ll ind){
    int curr=a[0];
    int prev=a[0];
    int ans=INT_MIN;
    for(int i=1;i<n;i++){
        curr=max(prev+a[i], a[i]);
        prev=curr;
        ans=max(ans,prev);
    }
    return ans;
}

int main(){
    
        cin>>n;
        a.resize(n);
        vector<ll> dp(n+1,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<f(0,dp)<<endl<<f_optm(0);
}