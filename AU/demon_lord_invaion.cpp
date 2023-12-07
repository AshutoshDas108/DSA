#include <bits/stdc++.h>
using namespace std;

int main() {
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
  cin>>a[i];
}
multiset<int> ms;
int l=0,r=0;
vector<int> ans;
for(int i=0;i<n;i++){
  l=i;
while((r-l)<=k){
  if(r<n){
  ms.insert(a[r]);
  }
  r++;
}
cout<<*(--ms.end())<<" ";
if(l>=k){
  ms.erase(ms.find(a[l-k]));
}
}
  return 0;
}