#include <bits/stdc++.h>
using namespace std;


void NSL(vector<int>& h, vector<int>& l, int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            l.push_back(-1);
        }
        else{
            while(!st.empty()){
                if(h[st.top()]<h[i]) break;

                st.pop();
            }
            if(!st.empty()){
                l.push_back(st.top());
            }
            else{
                l.push_back(-1);
            }
        }
        st.push(i);
    }
}


void NSR(vector<int>& h, vector<int>& r, int n){
   stack <int> st;
   for(int i=n-1;i>=0;i--){
     if(st.empty()){
        r.push_back(n);
     }
     else{
        while(!st.empty()){
            if(h[st.top()]<h[i]) break;

            st.pop();
        }
        if(!st.empty()){
            r.push_back(st.top());
        }
        else{
            r.push_back(n);
        }
     }
     st.push(i);
   }
}


int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
   vector<int> l;
   vector<int> r;
   NSL(h,l,n);
   NSR(h,r,n);
   reverse(r.begin(),r.end());
//    for(auto it: l){
//     cout<<it<<" ";
//    }
//    cout<<endl;
//    for(auto it: r){
//     cout<<it<<" ";
//    }
   cout<<endl;
   int ans=0;
   for(int i=0;i<n;i++){
      int area=h[i]*(r[i]-l[i]-1);
      ans=max(ans,area);
   }
   cout<<ans<<endl;
}