//#define Q422
#ifdef Q422

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

int dx[] = {-1 , -1 , 0 , 0 , 1 , 1 , 1};
int dy[] = {-1 , 1 , -1 , 1 , -1 , 0 , 1};
int n;
vvc vec;

bool check(int i , int j){
    return  (i >= 0 && i < n && j >= 0 && j < n);
}

ii fnd (string a , int i , int j){
    for (int mv = 0; mv < 7; ++mv) {
        int x = i + dx[mv] , y = j + dy[mv];
        if (check(x , y) && vec[x][y] == a[1]){
            int indx = 1;
            while (check(x, y) && vec[x][y] == a[indx] && indx < a.size()) {
                x += dx[mv]; y += dy[mv];
                indx++;
            }
            if (indx == a.size())
                return make_pair(x - dx[mv] , y - dy[mv]);
        }
    }
    return make_pair(-1 , -1);
}

int main() {

    ios::sync_with_stdio(0);

    cin >> n;
    vec.clear();
    vec.resize(n + 1, vc(n + 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> vec[i][j];
    string a;
    while (cin >> a && a != "0") {
        bool ok = false;
        ii ans , ans1;
        for (int i = 0; i < n && !ok; ++i)
            for (int j = 0; j < n && !ok; ++j)
                if (vec[i][j] == a[0]){
                    if (a.size() > 1) {
                        ans = fnd(a, i, j);
                        if (ans.first != -1 && ans.second != -1) {
                            ok = true;
                            ans1 = make_pair(i, j);
                        }
                    }
                    else ans = make_pair(i , j) , ans1 = make_pair(i , j), ok = true;
                }
        if (ok) cout << ans1.first + 1 << "," << ans1.second + 1 << " " << ans.first + 1 << "," << ans.second + 1 << endl;
        else cout << "Not found\n";

    }


    return 0;
}

#endif