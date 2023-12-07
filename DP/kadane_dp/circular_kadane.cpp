#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll n;
vector<ll> a;


ll f(vector<ll>& v){
    ll curr=0;
    ll ans=INT_MIN;
    
      for(ll i=0,steps=n;i<2*n and steps>=0;i++,steps--){
        curr=max(curr+a[i], a[i]);
        ans=max(ans,curr);
      }
    
    return ans;
}

int main(){   
        cin>>n;
        a.resize(n);
        //vector<vector<ll>> dp(n,vector<ll> (n+1,0));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll> b(2*n);
        for(int i=0;i<2*n;i++){
           if(i>=n)
           b[i]=a[i-n];
           else
           b[i]=a[i];
        }
        cout<<f(b);
}