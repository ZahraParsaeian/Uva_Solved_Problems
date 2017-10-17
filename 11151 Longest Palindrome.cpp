//#define Q11151
#ifdef Q11151

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
typedef vector<string> vs;
#define inf 1e9
#define sup 1e-9

string a;
vvi memo;

int fnd(int l , int r){
    if (l == r) return 1;
    if (l + 1 == r){
        if (a[l] == a[r]) return 2;
        return 1;
    }
    if (memo[l][r] != inf) return memo[l][r];
    if (a[l] == a[r]) memo[l][r] = 2 + fnd(l + 1 , r - 1);
    else memo[l][r] = (max(fnd(l , r - 1) , fnd(l + 1 , r)));
    return memo[l][r];
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    cin.ignore();
    while (tc--){
        getline(cin , a);
        memo.clear(); memo.resize(a.size() + 1 , vi(a.size() + 1 , inf));
        cout << fnd(0 , int(a.size()) - 1) << endl;
    }

    return 0;
}

#endif