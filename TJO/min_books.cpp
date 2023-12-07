#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
std::vector<ll> a;

ll f(ll ind){
    if(ind>=n) return 0;

    ll skip=(ind+1>=n)?INT_MAX:(0+f(ind));
    ll pick=a[ind]+f(ind+1);
    ll ans=min(pick,skip);

    return ans;
}
int main(){   
        cin>>n;
        a.resize(n);
        //vector<vector<ll>> dp(n,vector<ll> (n+1,0));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<f(0)<<endl;
}