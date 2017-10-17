//#define Q575
#ifdef Q575

//Ac

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

    string a;
    while (cin >> a && a != "0"){
        int ans = 0;
        for (int i = a.size() - 1 , k = 2 ; i >= 0 ; i-- , k *= 2)
            if (a[i] - '0')
                ans += (a[i] - '0' ) * (k - 1);
        cout << ans << endl;
    }

    return 0;
}

#endif