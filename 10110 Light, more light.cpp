//#define Q10110
#ifdef Q10110

//AC

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
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

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int) i);
        }
}

ll numDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (PF * PF <= N) {
        ll power = 0;
        while (N % PF == 0) {
            N /= PF;
            power++;
        }
        ans *= (power + 1);
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= 2;
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

    ll n;
    sieve(10000000);
    while (cin >> n && n){
        ll ans = numDiv(n);
        if (ans % 2 == 0) cout << "no\n";
        else cout << "yes\n";
    }

    return 0;
}

#endif