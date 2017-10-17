//#define Q514
#ifdef Q514

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while(cin>>n && n){
        int m;
        while(cin>>m && m){
            vi vec;
            vec.push_back(m);
            for(int i=1;i<n;i++){
                cin>>m;
                vec.push_back(m);
            }
            vi vis(n);
            stack<int>s;
            bool check=true;
            for(int i=0;i<vec.size();i++) {
                if (!vis[vec[i] - 1]) {
                    for (int j = 0; j < vec[i]; j++) {
                        if (!vis[j]) {
                            s.push(j + 1);
                            vis[j] = 1;
                        }
                    }
                }
                if (vec[i] != s.top()) {
                    check = false;
                    break;
                } else {
                    s.pop();
                }
            }
            if(check)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        cout<<endl;
    }

    return 0;
}

#endif