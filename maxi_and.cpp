#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll maxiAnd(int n, vector<int>& a){
    int bits=INT_MAX;
    for(int i=0; i<n;i++){
        long long x=a[i];
        int c=0;
        while(x>0){
           c++;
           x=x>>1;
        }
        bits=min(bits,c);
    }
    //cout<<bits<<endl;
    long long num=0;
    int i=0;
    while(i<bits){
       num+=(pow(2,i));
       i++;
    }
    return num;
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