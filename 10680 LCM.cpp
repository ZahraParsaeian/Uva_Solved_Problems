//#define Q10680
#ifdef Q10680

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

ll sieve_size;
bitset<10000010> bs;
vi primes;
ull lcm;

void sieve(ll upperbound) {
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

void primeFactors(ll n) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= n) {
        while (n % PF == 0) {
            n /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if (n != 1) factors.push_back(n); // special case if n is a prime
    if(factors[0] == factors.back()) lcm *= factors.back();
    ll p = 10;
    lcm %= inf;
    while(lcm % p == 0) lcm /= p;

}

int main(){

    ios::sync_with_stdio(0);

    sieve(1000002);
    lcm = 1;
    vc ans;
    for(ll i = 2; i <= 1e6; i++){
        primeFactors(i);
        ans.push_back((lcm % 10) + '0');
    }
    int n;
    while (cin >> n && n){
        if (n == 1) cout << 1 << endl;
        else cout << ans[n - 2] << endl;
    }


    return 0;
}

#endif