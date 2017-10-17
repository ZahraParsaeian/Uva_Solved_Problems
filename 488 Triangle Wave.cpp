//#define Q488
#ifdef Q488

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

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        int a , b;
        cin >> a >> b;
        for (int j = 0; j < b; ++j) {
            for (int k = 1; k <= a; ++k) {
                for (int i = 0; i < k; ++i)
                    cout << k;
                cout << endl;
            }
            for (int k = a -1 ; k > 0; k-- ){
                for (int i = 0; i < k; ++i)
                    cout << k;
                cout << endl;
            }
            if (tc != 0 || j != b -1)
                cout << endl;
        }
    }

    return 0;
}

#endif