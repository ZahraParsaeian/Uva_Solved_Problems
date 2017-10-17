//#define Q941
#ifdef Q941

//AC
//Important one

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
typedef vector<string> vs;
#define inf 1e9
#define sup 1e-9

int main(){

    ios::sync_with_stdio(0);

    vll vec(21);
    vec[0] = 1;
    for (int i = 1; i < 21; ++i) vec[i] = vec[i - 1] * i;

    int tc; cin >> tc;
    while (tc--) {
        string a; cin >> a;
        ll per; cin >> per;
        for (int i = 0; i < a.size(); ++i) {
            sort(a.begin() + i , a.end());
            swap(a[i] , a[i + per / vec[a.size() - 1 - i]]);
            per %= vec[a.size() - 1 - i];
        }
        cout << a << endl;
    }

    return 0;
}
#endif