//#define Q10139
#ifdef Q10139

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
bitset<10000010> bs;
vll primes;
ll fact;

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

bool primeFactors(ll n) {
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        if (n % PF == 0) {
            int b = 0;
            while (n % PF == 0)
                n /= PF , b++;
            ll a = 0;
            while(fact / PF)
                a += fact / PF , PF *= primes[PF_idx];
            if (b > a) return false;
        }
        PF = primes[++PF_idx];
    }
    if (n != 1 && fact / n <= 0) return false;
    return true;
}

int main(){

    ios::sync_with_stdio(0);

    ll m;
    sieve(10000002);
    while (cin >> fact >> m) {
        if (primeFactors(m))  cout << m << " divides " << fact << "!\n";
        else cout << m << " does not divide " << fact << "!\n";
    }

    return 0;
}

#endif