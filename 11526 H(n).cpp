//#define Q11526
#ifdef Q11526

//Dont AC :((((((

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

int main(){

    ios::sync_with_stdio(0);

    int tc;
    cin >> tc;
    ll n;
    while (tc--){
        ll n;
        cin >> n;
        ll whr = sqrt(n) , pre , res = 0;
        for ( int i = 1; i <= whr; i++ ) {
            res += n / i;
            res += (i - 1) * (pre - (n / i)) ;
            pre = n / i;
        }
        res += whr * (pre - whr);
        cout << res << endl;
    }

    return 0;
}
#endif