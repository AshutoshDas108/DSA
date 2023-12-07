#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
 ll n;
 cin>>n;
 ll a[n];
 for(int i=0;i<n;i++){
   cin>>a[i];
 }
 stack<ll> st ;
 vector<ll> v ;
 for(int i=0;i<n;i++)
 {
   if(st.empty())
   {
     v.push_back(-1);
   }
   else
   {
     while(!st.empty())
     {
       if(st.top()>a[i])
          break;
          
       st.pop();
     }
     
     if(st.size()>0)
     v.push_back(st.top());
     else
     v.push_back(-1);
   }
   st.push(a[i]);
 }
 for(auto it:v){
   cout<<it<<" ";
 }
  return 0;

}