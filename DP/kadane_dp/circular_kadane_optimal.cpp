#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
std::vector<ll> a;



ll f_case1(){
  ll curr=0;
  ll ans=INT_MIN;
  ans=max(ans,curr);
  for(int i=0;i<n;i++){
    curr=max(curr+a[i],a[i]);
    ans=max(ans,curr);
  }
  return ans;
}




ll f_case2(vector<ll>& v){
  ll curr=0;
  ll ans=INT_MIN;
  ans=max(ans,curr);
  for(int i=0;i<n;i++){
    curr=max(curr+v[i], v[i]);
    ans=max(ans,curr);
  }
  return ans;
}



int main() {
  cin>>n;
  a.resize(n);
  ll s=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    s+=a[i];
  }
  if(n==1) cout<<a[0]<<endl;
  else{
  vector<ll> b(n);
  for(int i=0;i<n;i++){
    b[i]=-a[i];
  }
  ll res1=f_case1();
  ll res2=f_case2(b);
  // cout<<s<<endl;
  // cout<<res1<<endl;
  // cout<<res2<<endl;
  if(res2==-s)
  cout<<*max_element(a.begin(),a.end())<<endl;
  else
  cout<<max(res1, (s+res2));
  }
  return 0;

}