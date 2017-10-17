//#define Q10557
#ifdef Q10557

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
#define inf 1e9
#define sup 1e-9

int n;
vi dist , vis ;
vvii vec;

void blmnfrd() {
    dist.clear();
    dist.resize(n, -inf);
    dist[0] = 100;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n; ++j)
            for (auto k : vec[j])
                if (dist[j] + k.first > 0)
                    dist[k.second] = max(dist[k.second], dist[j] + k.first);
}

void dfs(int v){
    vis[v] = 1;
    for (auto i : vec[v])
        if(!vis[i.second])
            dfs(i.second);
}

/*bool chk() {
    for (int i = 0; i < n ; ++i)
        for (auto j : vec[i])
            if (dist[j.second] < dist[i] + j.first && dist[i] + j.first > 0 ) {
                dfs(i);
                if(vis[n - 1] && vis1[i])
                    return true;
            }
    return false;

}*/

int main(){

    ios::sync_with_stdio(0);

    while(cin >> n && (n != -1)) {
        vec.clear();
        vec.resize(n);
        int enrgy, b, num;
        for (int i = 0; i < n; ++i) {
            cin >> enrgy >> num;
            for (int j = 0; j < num; ++j) {
                cin >> b;
                vec[i].push_back(ii(enrgy, b - 1));
            }
        }
        blmnfrd();
        vis.clear(); vis.resize(n , 0);
        dfs(0);
        vi vis1 = vis;

        if(dist[n - 1] > 0) cout << "winnable" << endl;
        else {
            bool happen = false;
            for (int i = 0; i < n && !happen; ++i)
                for (auto j : vec[i])
                    if (dist[j.second] < dist[i] + j.first && dist[i] + j.first > 0) {
                        vis.clear(); vis.resize(n,0);
                        dfs(i);
                        if (vis[n - 1] && vis1[i]) {
                            happen = true;
                            break;
                        }
                    }
            //if(chk())  cout << "winnable" << endl;
            if (happen) cout << "winnable" << endl;
            else cout << "hopeless\n";
        }
    }

    return 0;
}

#endif