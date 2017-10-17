//#define Q10334
#ifdef Q10334

//Done in pycharm

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

void fill(){
    ll a = 2 , b = 1;
    vec.push_back(1) ; vec.push_back(2);
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(a + b);
        ll tmp = a;
        a = a + b;
        b = tmp;
    }
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    fill();
    while (cin >> n){
        cout << vec[n] << endl;
    }

    return 0;
}

#endif