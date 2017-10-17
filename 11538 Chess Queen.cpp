//#define Q11538
#ifdef Q11538

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
#define inf 1e9
#define sup 1e-9

int main(){

    ios::sync_with_stdio(0);

    ll m , n;
    while(cin >> n >> m && (n || m)){
        ll mn = min (m , n);
        ll dig = (mn * (mn - 1) / 2) * (abs(n - m) + 1) + mn * (mn -1) * (mn - 2) / 3;
        ll rc = n * (n - 1) * m / 2 + n * m * (m - 1) / 2;
        ll ans = dig * 2 + rc;
        cout << ans * 2 << endl;
    }

    return 0;
}

#endif