//#define Q10235
#ifdef Q10235

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
bool isPrime(ll N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < (int) primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int main(){

    ios::sync_with_stdio(0);

    sieve(10000000);

    int n;
    while (cin >> n){
        int a = 0;
        int size = int(to_string(n).size());
        size--;
        int num = n;
        while (num){
            a += (num % 10) * pow(10 , size);
            num /= 10;
            size--;
        }
        //cout << "a  " << a << endl;
        if (isPrime(n) && isPrime(a) && a != n)
            cout << n <<" is emirp.\n";
        else if (isPrime(n))
            cout << n <<" is prime.\n";
        else
            cout << n <<" is not prime.\n";
    }

    return 0;
}

#endif