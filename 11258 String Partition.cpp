//#define Q11258
#ifdef Q11258

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
typedef vector<string> vs;
#define inf 1e9
#define sup 1e-9

ll lim = pow(2 , 31);
vll memo;
string a;

ll fnd(int indx){
    if (indx == a.size()) return 0;
    ll &ans = memo[indx];
    if (ans != -1) return ans;
    ll num = 0;
    for (int i = indx; i < a.size(); i++){
        num = num * 10 + (a[i] - '0');
        if (num >= lim)
            break;
        ans = max(ans , num + fnd(i+ 1));
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while(tc--){
        cin >> a;
       memo.assign(a.size() + 10 , -1);
        cout << fnd(0) << endl;
    }

    return 0;
}

#endif