//#define Q644
#ifdef Q644

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

    string a;
    int cont = 1;
    while (cin >> a){
        vs vec;
        while (a != "9"){
            vec.push_back(a);
            cin >> a;
        }
        bool ok = true;
        unsigned long s;
        for (int i = 0; i < vec.size(); ++i) {
            for (int j = 0; j < vec.size(); ++j) {
                if (i != j) {
                    s = vec[j].find(vec[i]);
                    if (s == 0) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok)
                break;
        }
        if (ok) cout << "Set " << cont++ << " is immediately decodable\n";
        else cout << "Set " << cont++ << " is not immediately decodable\n";
    }

    return 0;
}

#endif