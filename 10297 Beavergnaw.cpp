//#define Q10297
#ifdef Q10297

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
typedef unsigned long long ull;
typedef pair<double , double > dd;
typedef vector<dd> vdd;
#define inf 1e9
#define sup 1e-9
#define pi acos(-1)

int main(){

    ios::sync_with_stdio(0);

    double D , v;
    while (cin >> D >> v && (D || v)){
        double powD = D * D * D - (v * 6.0) / pi;
        double ans = pow (powD, (1.0 / 3.0));
        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}

#endif