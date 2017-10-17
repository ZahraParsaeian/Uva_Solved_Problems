//#define Q988
#ifdef Q988

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef  stack<int> si;
typedef queue<int> qi;
typedef map<int,int> mii;
#define inf 1e9
#define sup 1e-9

vvi adj;
vi vis;
vi order;

void topsort(int v){
    vis[v] = 1;
    for (auto i : adj[v])
        if (!vis[i])
            topsort(i);
    order.push_back(v);
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    int cont = 0;
    while (cin >> n) {
        if (cont++)
            cout << endl;
        vi ways(n, 0);
        vis.clear();
        vis.resize(n, 0);
        adj.clear();
        adj.resize(n);
        order.clear();
        vi vec;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            int a;
            for (int j = 0; j < num; ++j) {
                cin >> a;
                adj[i].push_back(a);
            }
        }
        ways[0] = 1;
        topsort(0);
        int ans = 0;
        for (int i = order.size() - 1; i >= 0; i--) {
            if (adj[order[i]].size() == 0)
                ans += ways[order[i]];
            for (auto j : adj[order[i]])
                ways[j] += ways[order[i]];
        }

        cout << ans << endl;
    }

    return 0;
}

#endif