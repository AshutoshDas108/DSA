 queue <pair<int,pair<int,int>>> q1=q;
            while(!q1.empty()){
              auto it=q1.front();
            cout<<it.first<<" "<<"{"<<it.second.first<<","<<it.second.second<<"}"<<endl;
            q1.pop();
            }