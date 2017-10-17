#define Q4425
#ifdef Q4425

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
typedef queue<ii> qii;
typedef pair<int , double> id;
typedef vector<id> vid;
typedef vector<vid> vvid;
typedef vector<ll> vll;
typedef vector<string> vs;
#define inf 1e9
#define sup 1e-9

int main() {

    ios::sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m && (n || m)) {
        vvc vec(n, vc(m));
        int how = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> vec[i][j];
                if (vec[i][j] == '0')
                    vec[i][j] = '#' , how++;
            }
        //vvc cop;
        int mx = -1;
        int cont = how;
        vvi vis(n, vi(m, 0));
        while (cont < m * n)
            for (int i = n - 1; i >= 0; i--)
                for (int j = 0; j < m; j++) {
                    vvc cop = vec;
                    if (!vis[i][j] && vec[i][j] != '#') {
                        bool happen = false;
                        int num;
                        num = cop[i][j] - '0';
                        cont += num;
                        for (int jj = j; jj < num + j; jj++)
                            cop[i][jj] = '#', vis[i][jj] = 1;
                        int ans = num;
                        for (int ii = i - 1; ii >= 0; ii--) {
                            happen = false;
                            for (int jj = 0; jj < m; jj++) {
                                if (cop[ii][jj] == '#') continue;
                                num = cop[ii][jj] - '0';
                                bool flag = true;
                                int j1 = jj;
                                for (int k = 0; k < num; k++, jj++)
                                    if (cop[ii + 1][jj] != '#') flag = false;
                                jj--;
                                if (flag) {
                                    for (int k = 0; k < num; k++, j1++)
                                        cop[ii][j1] = '#';
                                    ans+= num;
                                    happen = true;
                                }
                            }
                            if (!happen)
                                break;
                        }
                        mx = max(mx, ans);
                    }
                }
        cout << mx << endl;
    }

    return 0;
}

#endif