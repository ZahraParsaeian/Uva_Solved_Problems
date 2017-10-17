//In his name
//#define Q924
#ifdef Q924

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

int main(){

    ios::sync_with_stdio(0);

    int e , n , c;
    while(cin >> e){
        vvi vec(e);
        for (int i = 0; i < e; ++i) {
            cin >> n;
            for (int j = 0; j < n; ++j) {
                cin >> c;
                vec[i].push_back(c);
            }
        }
        int t; cin >> t;
        while(t--) {
            //vector<ii> ans;
            int ansm = 0,ansd;
            queue<int> a, b;
            cin >> n;
            a.push(n);
            int cont = 1;
            vi vis(e,0);
            vis[n] = 1;
            while(!a.empty() || !b.empty()){
                while(!a.empty()){
                    c = a.front(); a.pop();
                    for (auto i : vec[c]){
                        if(!vis[i]) {
                            b.push(i);
                            vis[i] = 1;
                        }
                    }
                }
                if(b.size() > ansm){
                    ansm = b.size();
                    ansd = cont;
                }
                cont++;
                while(!b.empty()){
                    a.push(b.front());
                    b.pop();
                }
            }
            if(ansm)
                cout << ansm << " " << ansd<<endl;
            else cout << 0 << endl;
        }
    }

    return 0;
}

#endif