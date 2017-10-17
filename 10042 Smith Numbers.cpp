//#define Q10043
#ifdef Q10043

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

vi vec;

bitset<10000000> bs;
vi primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= 10000000; i++)
        if (bs[i]) {
            for (ll j = i * i; j <= 10000000; j += i) bs[j] = 0;
            primes.push_back((int) i);
        }
}

bool isPrime(ll N) {
    if (N <= 10000000) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
    while (PF * PF <= N) {
        while (N % PF == 0) { N /= PF; factors.push_back(PF); }
        PF = primes[++PF_idx];
    }
    if (N != 1) factors.push_back(N);
    return factors;
}

int sum (ll n){
    int ans = 0;
    while (n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int sumoffact( ll n ){
    int ans = 0;
    vi v = primeFactors(n);
    for (int i = 0; i < v.size(); ++i)
        ans += sum (v[i]);
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

    sieve();
    int tc; cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        while (n++){
            if (isPrime(n))
                continue;
            if (sum(n) == sumoffact(n))
                break;
        }
        cout << n << endl;
    }

    return 0;
}

#endif