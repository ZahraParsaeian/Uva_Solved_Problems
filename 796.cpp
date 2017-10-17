#define Q796
#ifdef Q796

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vi dfs_low , dfs_num , dfs_parent ;
vii bri;
vvi vec;
int cont ;

void artiBri(int u) {
    dfs_low[u] = dfs_num[u] = cont++;
    for (auto &i : vec[u]) {
        if (dfs_num[i] == -1) {
            dfs_parent[i] = u;
            artiBri(i);
            if (dfs_low[i] > dfs_num[u])
                bri.push_back(make_pair(u, i));
            dfs_low[u] = min(dfs_low[i], dfs_low[u]);
        } else if (i != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[i]);
    }
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    while(cin >> n) {
        int a, num, b;
        char c;
        cont = 0;
        dfs_num.clear();
        dfs_num.resize(n, -1);
        dfs_low.clear();
        dfs_low.resize(n);
        dfs_parent.clear();
        dfs_parent.resize(n);
        vec.clear();
        vec.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a >> c >> num >> c;
            for (int j = 0; j < num; ++j) {
                cin >> b;
                vec[a].push_back(b);
            }
        }
        for (int k = 0; k < n; ++k)
            if (dfs_num[k] == -1)
                artiBri(k);
        sort(bri.begin(), bri.end());
        cout << bri.size() << " critical links" << endl;
        for (int l = 0; l < bri.size(); ++l)
            cout << bri[l].first << " - " << bri[l].second << endl;

    }

    return 0;
}

#endif