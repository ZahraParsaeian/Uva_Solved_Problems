//#define Q10394
#ifdef Q10394

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
bitset<20000010> bs;
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

vii vec;
void fill(){
    for (int i = 0; i < primes.size() - 1; ++i)
        if (primes[i + 1] - primes[i] == 2)
            vec.push_back(ii(primes[i] , primes[i + 1]));
}

int main() {

    ios::sync_with_stdio(0);

    sieve(20000010);
    fill();
    int n;
    while (cin >> n){
        cout << "(" << vec[n - 1].first << ", " << vec[n - 1].second << ")" << endl;
    }


    return 0;
}

#endif