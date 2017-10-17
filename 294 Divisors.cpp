//#define Q294
#ifdef Q294

//Ac

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

ll numofDiv(ll n){
    ll pf_indx = 0 , pf = primes[pf_indx] , ans = 1;
    while (pf * pf <= n){
        ll power = 0;
        while (n % pf == 0){
            n /= pf;
            power++;
        }
        ans *= power + 1;
        pf = primes[++pf_indx];
    }
    if (n != 1) ans *= 2;
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

    sieve(10000010);
    int tc;  cin >> tc;
    while (tc--){
        ll a , b;
        cin >> a >> b;
        ll mx = -1 , final;
        for (ll i = a; i <= b; i++){
            ll ans = numofDiv(i);
            if (ans > mx)
                mx = ans, final = i;
        }
        cout << "Between " << a << " and " << b << ", " << final << " has a maximum of " << mx << " divisors.\n";
    }

    return 0;
}

#endif