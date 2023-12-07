#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(vector<int>& in, vector<int>& out, int n){
   stack<int> st;
   int i=0,j=0;
   while(i<n or j<n){
    if(in[i]==out[j]) {
        i++;
        j++;
    }
    else{
        if(st.empty() or st.top()!=out[j]){
            st.push(in[i]);
            i++;
        }
        else{
           st.pop();
           j++;
        }
    }
   }
   if(st.empty()) cout<<"yes"<<endl;
   else cout<<"no"<<endl;
}
int main(){
  vector<int> in={7,6,2,5,3,4,8,10,4,9};
  vector<int> out={6,2,7,4,5,8,3,10,9,4};
  solve(in,out,10);
}