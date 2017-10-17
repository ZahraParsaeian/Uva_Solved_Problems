#define Q10805
#ifdef Q10805

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

vi p , vis ;
vvi vec , adj , ans;

int main() {

    ios::sync_with_stdio(0);

    int tc , m , n , cont = 1;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        vec.clear();
        vec.resize(n + m , vi(n + m , inf));
        for (int i = 0; i < n + m; ++i) 
            vec[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            vec[a][b] = 2;
            vec[b][a] = 2;
            vec[n + i][a] = vec[a][n + i] = 1;
            vec[n + i][b] = vec[b][n + i] = 1;
        }
        for (int k = 0; k < n + m; ++k)
            for (int i = 0; i < n + m; i++)
                for (int j = 0; j < n + m; ++j)
                    vec[i][j] = min (vec[i][j] , vec[i][k] + vec[k][j]);
        int mn = inf;
        for (int i = 0; i < m + n; ++i) {
            int tmp = -1;
            for (int j = 0; j < n; ++j)
                tmp = max (tmp , vec[i][j]);
            mn = min (tmp , mn);
        }
        cout << "Case #"<<cont++<<":\n"<<mn << endl<<endl;
    }

    return 0;
}

#endif