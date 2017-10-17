//#define Q11572
#ifdef Q11572

//AC

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc;
    cin>>tc;
    while(tc--){
        int num,a;
        cin>>num;
        vector<int>vec;
        for(int i=0;i<num;i++){
            cin>>a;
            vec.push_back(a);
        }
        priority_queue<int>tool;
        int index=0;
        map<int,int> m;
        for(int i=0;i<vec.size();i++){
            if(m.count(vec[i])) {
                if (m[vec[i]] >= index) {
                    tool.push(i - index);
                    index = m[vec[i]] + 1;
                }
                m[vec[i]] = i;

            }
            else
                m[vec[i]]=i;
        }
        tool.push(num-index);
        cout<<tool.top() <<endl;

    }

    return 0;
}

#endif