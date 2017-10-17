//#define Q374
#ifdef Q374

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
typedef unsigned long long ull;
#define inf 1000000000
#define sup 1e-9f

ll fast(ll a , ll p , ll mod){
    ll res = 1 , power = p, val = a;
    while (power > 0){
        if (power & 1){
            res *= val;
            res %= mod;
        }
        val *= val;
        val %= mod;
        power /= 2;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(0);

    ll a,power , mod;
    while ( cin >> a >> power >> mod){
        ll ans = fast(a , power , mod);
        ans %= mod;
        cout << ans << endl;
    }

    return 0;
}

#endif