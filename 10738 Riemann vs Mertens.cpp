//#define Q10738
#ifdef Q10738

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

vi mu(1000010 , inf);
vi M(1000010);

void fill(){
    mu[1] = 1;
    for (ll i = 2; i < 1000010; i++) {
        ll indx = 0, pf = primes[indx] , num = i;
        if (mu[i] != 0) {
            ll t = 0;
            bool ok = true;
            while (pf * pf <= num) {
                ll pow = 0;
                if (num % pf == 0) t++;
                while (num % pf == 0)
                    pow++, num /= pf;
                if (pow > 1){
                    mu[i] = 0;
                    for (ll j = i; j < 1000010; j+= i)
                        mu[j] = 0;
                    ok = false;
                    break;
                }
                pf = primes[++indx];
            }
            if (ok && num != 1) t++;
            if (ok && t % 2 == 0) mu[i] = 1;
            else if (ok && (t % 2))mu[i] = -1;
        }
    }
    M[1] = 1;
    for (int i = 2; i < 1000010; i++)
        M[i] = M[i - 1] + mu[i];
}

int main(){

    ios::sync_with_stdio(0);

    sieve(1000010);
    fill();
    int n;
    while (cin >> n && n){
        cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << endl;
    }

    return 0;
}

#endif