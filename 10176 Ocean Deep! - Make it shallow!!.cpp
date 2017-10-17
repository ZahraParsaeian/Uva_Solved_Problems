//#define Q10176
#ifdef Q10176

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

ll fast(int a , int p , int mod){
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

    char b;
    while (cin >> b){
        string a;
        a += b;
        while (cin >> b && b != '#')
            a += b;
        int power = 0 ;
        ll ans = 0;
        for (int i = a.size() - 1; i >= 0; i--){
            if (a[i] == '1') {
                ans += fast(2 , power , 131071);
                ans %= 131071;
            }
            power++;
        }
        if (ans == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

#endif