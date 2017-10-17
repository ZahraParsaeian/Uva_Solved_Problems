//#define Q10751
#ifdef Q10751

//AC

#include <bits/stdc++.h>

using namespace std;

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
#define inf 1e9
#define sup 1e-9

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        if (n == 1) cout << "0.000" << endl;
        else cout << fixed << setprecision(3) << pow(n - 2 , 2) * (sqrt(2) - 1) + pow (n , 2) << endl;
        if(tc) cout << endl;
    }

    return 0;
}

#endif