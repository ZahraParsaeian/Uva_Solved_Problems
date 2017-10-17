//#define Q10759
#ifdef Q10759

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
typedef vector<vll> vvll;
typedef unsigned long long ull;
#define inf 1000000000
#define sup 1e-9f

ll x;
vvll memo;

ll gcd (ll a , ll b){
    return ((b == 0) ? a : gcd(b , a % b));
}

ll prob(int dice_left , ll score){
    score = min (score , x);
    if (memo[dice_left][score] != - inf) return memo[dice_left][score];
    if (!dice_left) return score >= x ? 1 : 0;
    ll ans = 0;
    for (int i = 1; i <= 6; i++)
        ans += prob(dice_left - 1 , score + i);
    return memo[dice_left][score] = ans;
}

int main() {

    ios::sync_with_stdio(0);

    ll n;
    while (cin >> n >> x && (n || x)) {
        memo.clear();
        memo.resize(n + 1, vll(x + 10, -inf));
        ll dn = pow(6.0, n);
        ll ans = prob(n, 0);
        ll d = gcd(ans, dn);
        ans /= d;
        dn /= d;
        if (ans == 0) cout << 0 << endl;
        else if (dn == 1) cout << 1 << endl;
        else cout << ans << "/" << dn << endl;
    }

    return 0;
}

#endif