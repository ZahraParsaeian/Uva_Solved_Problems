//#define Q10010
#ifdef Q10010

//AC

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

vvc vec;
int m,n;
vvi vis;
vii ans;
ii an;

int dx[] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};

bool check(int i , int j){
    return  (i >= 0 && i < m && j >= 0 && j < n);
}

bool fnd(string a /*, int indx */, int i , int j) {
    /*if (indx == a.size()) return true;
    for (int mv = 0; mv < 8; mv++)
        if (check(i + dx[mv], j + dy[mv])) {
            if (vec[i + dx[mv]][j + dy[mv]] == a[indx]) {
                fnd(a, indx + 1, i + dx[mv], j + dy[mv]);
            }

        }
    return false;*/
    for (int mv = 0; mv < 8; ++mv) {
        int indx = 1;
        int x = i + dx[mv] , y = j + dy[mv];
        if (!check(x , y) || vec[x][y] != a[indx]) continue;
        while (vec[x][y] == a[indx]){
            indx++;
            if (indx == a.size()) return true;
            x += dx[mv] ; y += dy[mv];
            if (!check(x , y)) break;
        }
    }
    return false;
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        cin >> m >> n;
        vec.clear(); vec.resize(m , vc(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                char aa;
                cin >> aa;
                vec[i][j] = tolower(aa);
            }
        int k; cin >> k;
        for (int i = 0; i < k; ++i) {
            string a; cin >> a;
            transform(a.begin(), a.end(), a.begin(), ::tolower);
            bool ok = false;
            for (int l = 0; l < m && !ok; l++){
                for (int d = 0; d < n && !ok ; d++){
                    if (vec[l][d] == a[0]) {
                        if (fnd(a, l, d)) {
                            ok = true;
                            cout << l + 1 << " " << d + 1 << endl;
                        }
                    }
                }
            }
        }
        if (tc) cout << endl;
    }
    return 0;
}

#endif