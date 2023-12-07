#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& v){
    
    std::stack<string> st ;
    for(int i=0;i<v.size();i++){
        st.push(v[i]);
    }
    while(!st.empty()){
        string x=st.top();
        int l=x.length();
        if(l>=2)
        cout<<x[l-2]<<x[l-1];
        else
        cout<<x[l-1];
        st.pop();
    }
    cout<<endl;
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<string> str;
	map<string,int> mp; 
	for(int i=0;i<n;i++){
	    string y;
	    cin>>y;
	    str.push_back(y);
	    mp[y]++;
	}
    cout<<"------------------------"<<endl;
    for(auto it:mp){
        cout<<it.first<<endl;
        if(mp[it.first]>1){
            
        }
    }
    cout<<"------------------------"<<endl;
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<endl;
    }
    cout<<"------------------------"<<endl;
	solve(str);
	return 0;
}


// int main(){
//     // int a[7]={11, 2, 3, 4, 55, 6,9};
//     // string s[5]={"avc", "abc", "aaxx", "fdserk"};
//     // unordered_set<int> s1;
//     // unordered_set<string> s2;
//     // for(int i=0;i<7;i++){
//     //     s1.insert(a[i]);
//     //     s2.insert(s[i]);
//     // }
//     // for(auto it:s1){
//     //     cout<<it<<" ";
//     // }
//     // cout<<endl;
//     // for(auto it:s2){
//     //     cout<<it<<" ";
//     // }
//     // cout<<endl;
//     unordered_set<string> st;
//     for(int i=0;i<9;i++){
//         string s;
//         cin>>s;
//         st.insert(s);
//     }
//     cout<<"-------------------"<<endl;
//     for(auto it:st){
//         cout<<it<<endl;
//     }
// }