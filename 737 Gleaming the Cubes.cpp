//#define Q737
#ifdef Q737

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

struct triple{
    int x , y , z;
    triple(){ x = y = z = 0; }
    triple(int _x , int _y , int _z) { x = _x ; y = _y ; z = _z; }
};

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n){
        int x,y,z , sze;
        triple start(-inf , -inf , -inf);
        triple final(inf , inf , inf);
        for (int i = 0; i < n; i++){
            cin >> x >> y >> z >> sze;
            start.x = max (x, start.x);
            start.y = max (y , start.y);
            start.z = max (z , start.z);
            final.x = min (x + sze , final.x);
            final.y = min (y + sze , final.y);
            final.z = min (z + sze , final.z);
        }
        int ans = ((final.x - start.x) * (final.y - start.y) * (final.z - start.z));
        if (ans >= 0) cout << ans << endl;
        else cout << 0 << endl;
    }

    return 0;
}

#endif