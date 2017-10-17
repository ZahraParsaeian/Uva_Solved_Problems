//#define Q10913
#ifdef Q10913

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

int n , k;
vvi vec ;
vector<vvvi> memo;
vvi vis;

int dx[] = {0 , 1 , 0};
int dy[] = {1 , 0 , -1};

int go (ii cur , int nega_left , int j){
    if (nega_left < 0) return -inf;
    if (cur.first == n - 1 && cur.second == n - 1) return 0;
    if (memo[cur.first][cur.second][nega_left][j] != -inf) return memo[cur.first][cur.second][nega_left][j];
    int ans = - inf - 1;
    int next;
    if (cur.first + 1 < n){
        next = go(ii(cur.first + 1, cur.second), vec[cur.first + 1][cur.second] < 0 ? nega_left - 1 : nega_left , 0);
        if (next > -inf) ans = max(ans, next + vec[cur.first + 1][cur.second]);
    }
    if (j == 0 || j == 1)
        if (cur.second + 1 < n){
            next = go(ii(cur.first, cur.second + 1), vec[cur.first][cur.second + 1] < 0 ? nega_left - 1 : nega_left , 1);
            if (next > -inf) ans = max(ans, next + vec[cur.first][cur.second + 1]);
        }

    if (j == 0 || j == 2)
        if (cur.second -1 >= 0){
            next = go(ii(cur.first, cur.second - 1), vec[cur.first][cur.second - 1] < 0 ? nega_left - 1 : nega_left , 2);
            if (next > -inf) ans = max(ans, next + vec[cur.first][cur.second - 1]);
        }

    return memo[cur.first][cur.second][nega_left][j] = ans;
}

int main(){

    ios::sync_with_stdio(0);

    int tc = 1;
    while (cin >> n >> k && (n || k)){
        vec.clear(); vec.resize(n , vi (n));
        memo.clear(); memo.resize(n , vvvi (n , vvi(k + 1 , vi (3,-inf))));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> vec[i][j];
        int ans = go (ii(0 , 0) , vec[0][0] < 0 ? k - 1 : k , 0);
        cout << "Case "<<tc++<<": ";
        if (ans < -inf ) cout << "impossible\n";
        else cout << ans + vec[0][0] << endl;
    }

    return 0;
}

#endif