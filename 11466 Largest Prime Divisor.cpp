//#define Q11466
#ifdef Q11466

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

ll _sieve_size;
bitset<100000010> bs;
vll primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}
ll primeFactors(ll N) {
    vll factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N) {
        if (N % PF == 0)
            factors.push_back(PF);
        while (N % PF == 0)
            N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N);
    return factors.size() >= 2 ? factors.back() : -1;
}

int main(){

    ios::sync_with_stdio(0);

    sieve(2 * 1e7 + 100);
    ll n;
    while (cin >> n && n){
        cout << primeFactors(abs(n)) << endl;
    }

    return 0;
}


#endif