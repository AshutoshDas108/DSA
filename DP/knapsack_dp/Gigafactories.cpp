#include <bits/stdc++.h>
using namespace std;

int N,C;
std::vector<int>n ;
vector<int> c;

int knapSack(int i ,int j){
  if(i==N or j==0) return 0;
  int skip=0+knapSack(i+1,j);
  int pick=0;
  if(c[i]<=j)
   pick=n[i]+knapSack(i+1,j-c[i]);
  
  return max(skip,pick);
}

int main() {
  cin>>N>>C;
  c.resize(N);
  n.resize(N);
  vector<vector<int>> dp(N+1, vector<int>(C+1,-1));
  for(int i=0;i<N;i++){
    cin>>c[i]>>n[i];
  }
  cout<<knapSack(0,C);
  return 0;
}