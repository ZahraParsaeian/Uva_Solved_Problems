//#define Q10111
#ifdef Q10111

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
#define inf 1e9
#define sup 1e-9
#define x 0
#define o 1
#define dot 2

vvi table;
ii ans;

bool check(int w , int xx , int yy) {
    int col = 0, row = 0, dig1 = 0, dig2 = 0;
    for (int i = 0; i < 4; i++)
        col += (table[xx][i] == w) , row += (table[i][yy] == w) , dig1 += (table[i][i] == w) , dig2 += (table[i][3 - i] == w);
    return (col == 4 || row == 4 || dig1 == 4 || dig2 == 4);
}

bool can(int w) {
    if (w == x)
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (table[i][j] == 2) {
                    table[i][j] = x;
                    if (check(x , i , j)) {
                        ans = ii(i, j);
                        table[i][j] = 2;
                        return true;
                    }
                    if (can(o)) {
                        ans = ii(i, j);
                        table[i][j] = 2;
                        return true;
                    }
                    table[i][j] = 2;
                }
    else {
        bool ok = false;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (table[i][j] == 2) {
                    ok = true;
                    table[i][j] = o;
                    if (check(o , i , j)) {
                        table[i][j] = 2;
                        return false;
                    }
                    if (!can(x)) {
                        table[i][j] = 2;
                        return false;
                    }
                    table[i][j] = 2;
                }
        if (ok) return true;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(0);

    char a;
    while (cin >> a && a != '$'){
        table.clear();
        table.resize(4 , vi(4));
        char b;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> b;
                if (b == 'x') table[i][j] = x;
                else if (b == 'o') table[i][j] = o;
                else table[i][j] = 2;
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        if(can(x)) cout << ans.first << " " << ans.second << endl;
        else cout << "#####\n";
    }

    return 0;
}

#endif