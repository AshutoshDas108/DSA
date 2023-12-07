#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int t,n;
vector<int> h;

int f(int ind, vector<int>& h, int num){
    if(ind==n) return 0;

    int dont_take=f(ind+1,h, num);
    int take=0;
    if(num+ind<=n)
    take=h[ind]+f(ind,h,num+ind+1);

    int ans=max(take,dont_take);
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        h.resize(n);
        vector<vector<int>>(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        cout<<f(0,h,0)<<endl;
    }
}
