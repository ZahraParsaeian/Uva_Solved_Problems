//#define Q10219
#ifdef Q10219

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
typedef vector<vll> vvll;
#define inf 1e9
#define sup 1e-9

vvll memo;

int main(){

    int n , k;
    memo.resize(1000 , vll (1000 , -1));
    while (cin >> n >> k){
        double a = 0 , b = 0;
        k = max (k , n - k);
        for (int i = k + 1; i <= n; i++) a += log10(i);
        for (int i = 1 ; i <= n - k; i++) b += log10(i);
        cout << floor(a - b + 1) << endl;
    }
}

#endif