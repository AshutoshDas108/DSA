#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5;
int memo[N];

int f(int n){
  if(n==1) return 0;
  if(memo[n]!=-1) return memo[n];

  return memo[n]=1+(min({f(n-1),(n%2==0)?f(n/2):INT32_MAX,(n%3==0)?f(n/3):INT32_MAX}));
}
int main(){
    int n;
    cin>>n;
    memset(memo,-1,sizeof(memo));
    cout<<f(n)<<endl;
}