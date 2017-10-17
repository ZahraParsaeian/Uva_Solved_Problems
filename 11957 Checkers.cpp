//#define Q11957
#ifdef Q11957

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

int main(){

    ios::sync_with_stdio(0);

    int tc , n , cont = 1; cin >> tc;
    while( tc-- ) {
        cin >> n;
        vvc vec(n, vc(n)); vvi ans(n, vi(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> vec[i][j];
                if (vec[i][j] == 'W')
                    ans[i][j] = 1;
            }
        for (int i = n - 1; i >= 0; --i)
            for (int j = 0; j < n; ++j) {
                if (vec[i][j] == 'B') continue;
                if (i + 1 < n && j + 1 < n) {
                    if (vec[i + 1][j + 1] != 'B')
                        ans[i][j] += ans[i + 1][j + 1];
                    else if (i + 2 < n && j + 2 < n)
                        ans[i][j] += ans[i + 2][j + 2];
                }
                if (i + 1 < n && j - 1 >= 0) {
                    if (vec[i + 1][j - 1] != 'B')
                        ans[i][j] += ans[i + 1][j - 1];
                    else if (i + 2 < n && j - 2 >= 0)
                        ans[i][j] += ans[i + 2][j - 2];
                }
                ans[i][j] %= 1000007;
            }
        int javab = 0;
        for (int i = 0; i < n; ++i)
            javab += ans[0][i];
        cout << "Case " << cont++ << ": " << javab % 1000007<< endl;
    }

    return 0;
}

#endif