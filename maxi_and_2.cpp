#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll maxiAnd(int n, vector<int>& a){
    int max_xor=INT_MIN;
    for(int i=0;i<n;i++){
        max_xor=0;
        for(int k=0;k<=a[i];k++){
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxiAnd(n,a);
}