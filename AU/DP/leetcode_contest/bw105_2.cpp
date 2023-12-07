#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

 int minExtraChar(string s, vector<string>& dictionary) {
        // map<char,int> mp;
        // for(auto it:s){
        //     mp[it]++;
        // }
        for(auto it:dictionary){
            if(s.find(it)){
              
            }
        }
        int res=0;
        // for(auto it:mp){
        //     if(it.second>0){
        //         res++;
        //     }
        // }
        return res;
    }

    int main(){
        string s="leetscode";
        vector<string> d={"leet","code"};
        cout<<minExtraChar(s,d);
    }