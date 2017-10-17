//#define Q11264
#ifdef Q11264

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc; cin>>tc;
    while(tc--){
        int n;  cin>>n;
        vector<int>vec(n);
        for (int i = 0; i < n; ++i) {
            cin>>vec[i];
        }
        int sum=1,cont=1;
        for(int i=1;i<vec.size()-1;i++){
            if(sum+vec[i]<vec[i+1])
                sum+=vec[i],cont++;
        }
        if(sum<vec[vec.size()-1])
            cont++;
        cout<<cont<<endl;
    }

    return 0;
}

#endif