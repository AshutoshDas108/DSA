#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
   

   long long f(int ind, int p_or_s,int n, vector<int>& a){
        long long r;

        if(ind==0) {
            if(p_or_s)
            return a[0];
            else
            return 1;
        }

        long long pick=0;
        pick=a[ind]*f(ind-1,1,n,a);
        long long skip=0;
        skip=1*f(ind-1,0,n,a);
        

         r=max(pick,skip);
        //return max(a[ind]*f(ind+1,n,a),f(ind+1,n,a));
        return r;
   }

    long long maxStrength(vector<int>& nums) {
        for(auto it: nums){
            cout<<it<<" ";
        }
        cout<<endl;
        int n=nums.size();
        return f(n-1,1,n,nums);
    }
   
   int main(){
     vector <int> a={3,-1,-5,2,5,-9};
     cout<<maxStrength(a);
   }

