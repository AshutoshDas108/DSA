#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int n){
  if(n==1) return 0;

  return 1+(min({f(n-1),(n%2==0)?f(n/2):INT32_MAX,(n%3==0)?f(n/3):INT32_MAX}));
}
int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}