//#define Q10090
#ifdef Q10090

//AC

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
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

ll x , y , d;

void extendedEuclid(ll a, ll b) {
    if (b == 0) { x = 1; y = 0; d = a; return; }
    extendedEuclid(b, a%b);
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main(){

    ios::sync_with_stdio(0);

    ll c;
    while (cin >> c && c){
        ll c1 , c2 , n1 , n2;
        cin >> c1 >> n1 >> c2 >> n2;
        extendedEuclid(n1 , n2);
        if (c % d == 0) {
            ll n , m;
            n = (int)ceil(-1.0 * c * x / n2);
            m = (int)floor(c * y / (double)n1);
            ll ans1 = (x * c / d) + (n2 * n / d);
            ll ans2 = (y * c / d) - (n1 * n / d);
            ll ans3 = (x * c / d) + (n2 * m / d);
            ll ans4 = (y * c / d) - (n1 * m / d);
            ll cost1 = ans1 * c1 + ans2 * c2, cost2 = ans3 * c1 + ans4 * c2;
            if(m < n) cout << "failed\n";
            else {
                if (cost1 < cost2)
                    cout << ans1 << " " << ans2 << endl;
                else cout << ans3 << " " << ans4 << endl;
            }
        }
        else cout << "failed\n";


    }

    return 0;
}

#endif