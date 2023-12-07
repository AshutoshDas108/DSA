#include <bits/stdc++.h>
using namespace std;

std::stack<int> st ;

int main() {
 int q;
 cin>>q;
 while(q--){
   int op;
   cin>>op;
   if(op==0){
     st.pop();
   }
   else if(op==1){
     int w;
     cin>>w;
     if(st.size()==0 or w>st.top())
     st.push(w);
     else
     st.push(st.top());
   }
   else if(op==2){
     cout<<st.top()<<endl;
   }
 }
  return 0;

}