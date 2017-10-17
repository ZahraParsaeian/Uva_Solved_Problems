//#define Q11489
#ifdef Q11489

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
typedef unsigned long long ull;
#define inf 1000000000
#define sup 1e-9f

int main(){

    ios::sync_with_stdio(0);

    string a;
    vi vec,vis;
    int tc , cont = 1; cin >> tc;
    while (tc--){
        cin >> a;
        vis.clear(); vis.resize(a.size() , 0);
        vec.clear();
        int sum = 0;
        for (int i = 0; i < a.size(); ++i) {
            vec.push_back(a[i] - '0');
            sum += a[i] - '0';
        }
        int num = 1;
        while(sum) {
            num = abs(num - 1);
            bool ok = false;
            for (int i = 0; i < vec.size(); ++i) {
                if(!vis[i] && (sum - vec[i]) % 3 == 0){
                    vis[i] = 1;
                    sum -= vec[i];
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                num = abs(num - 1);
                break;
            }
        }
        cout << "Case " << cont++ << ": " ;
        if (num == 0) cout << 'S' << endl;
        else cout << 'T' << endl;
    }

    return 0;
}

#endif