//#define Q11357
#ifdef Q11357

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
        string a; cin >> a;
        map<char , int> m;
        bool happen = true;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == '(') {
                bool now = true;
                i++;
                while(a[i] != ')') {
                    if (isalpha(a[i]) && islower(a[i])) {
                        if (a[i - 1] == '~') {
                            if (m[a[i]] == 1)
                                now = false;
                            m[a[i]] = 2;
                        }
                        else {
                            if (m[a[i]] == 2)
                                now = false;
                            m[a[i]] = 1;
                        }
                    }
                    i++;
                }
                m.clear();
                if (now) {
                    happen = true;
                    break;
                }
                else happen = false;
            }
        }
        if (happen) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

#endif