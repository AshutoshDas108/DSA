#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int const m=1e9+7;
int t,n;
vector<int> a;

bool f(int ind,int sum, int target, vector<vector<int>>& dp){
    if(sum==target) return 1;
    if(ind==n) return sum==target;
    if(dp[ind][sum]!=-1) return dp[ind][sum];

    bool ans=f(ind+1,sum,target,dp);
    if(sum+a[ind]<=target)
      ans|=f(ind+1,sum+a[ind],target,dp);

    return dp[ind][sum]=ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        a.resize(n);
        int s=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        if(s%2==1) cout<<"NO"<<endl;
        else{
        vector<vector<int>> dp(n+1,vector<int>(s/2 +1,-1));
         if(f(0,0,s/2,dp)) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
        }
    }
}