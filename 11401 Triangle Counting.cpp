//#define Q11401
#ifdef Q11401

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
#define inf 1e9
#define sup 1e-9

vll vec;

ll cal() {
    vec.push_back(0);
    vec.push_back(1);
    ll add = 2;
    ll a = 2;
    for (int i = 2; i < 1000001; ++i) {
        vec.push_back(vec[i - 1] + a);
        i++;
        a += add;
        vec.push_back(vec[i - 1] + a);
        a += add;
        add++;
    }
}

int main(){

    ll n;
    cal();
    while (cin >> n && n > 2){
        cout << vec[n - 3] << endl;
    }
}

#endif