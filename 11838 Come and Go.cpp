//#define Q11838
#ifdef Q11838

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi dfs_low,dfs_num,s,vis;
vvi vec;

int counter, root;

bool TarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = counter++;
    s.push_back(u);
    vis[u] = 1;
    for (auto i : vec[u]) {
        if (dfs_num[i] == -1)
            if(!TarjanSCC(i))
                return false;
        if (vis[i])
            dfs_low[u] = min(dfs_low[u], dfs_low[i]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        if(u != root)
            return false;
        while (1) {
            int v = s.back();
            s.pop_back();
            vis[v] = 0;
            if (v == u) break;
        }
    }
    return true;
}

int main(){

    ios::sync_with_stdio(0);

    int v, e, a, b, c;
    while(cin >> v >> e && (e || v)) {
        counter = 0;
        vec.clear();      vec.resize(v);
        vis.clear();      vis.resize(v, 0);
        dfs_num.clear();  dfs_num.resize(v, -1);
        dfs_low.clear();  dfs_low.resize(v);
        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> c;
            vec[a - 1].push_back(b - 1);
            if (c == 2)
                vec[b - 1].push_back(a - 1);
        }
        root  = 0;
        bool ok = true;
        if(!TarjanSCC(0)) cout << 0 << endl;
        else {
            for (int j = 0; j < v; ++j) {
                if (dfs_num[j] == -1) {
                    ok = false;
                    cout << 0 << endl;
                    break;
                }
            }
            if (ok) cout << 1 << endl;
        }
    }

    return 0;
}

#endif