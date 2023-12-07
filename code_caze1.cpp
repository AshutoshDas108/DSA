#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

vector<int> result(ll n, vector<int>& a, int  q, vector<vector<int>>& qr, int x){
      vector<int>b(q);
        int sm=0;
        for(int i=0;i<n;i++){
         sm+=a[i];
        }
      for(int i=0;i<q;i++){
        sm-=a[qr[i][0]];
        a[qr[i][0]]=qr[i][1];
        sm+=a[qr[i][0]];
        if(sm%x==0)
        b[i]=sm/x;
        else
        b[i]=sm/x + 1;
      }
      return b;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    ll sm=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }
    int x;
    cin>>x;
    int q;
    cin>>q;
    vector<vector<int>> qr(q,vector<int>(2,0));
    for(int i=0;i<q;i++){
        cin>>qr[i][0]>>qr[i][1];
    }
    vector<int> ans=result(n,a,q,qr,x);
    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
}