//#define Q498
#ifdef Q498

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


int main(){

    ios::sync_with_stdio(0);

    string a;
    while (getline(cin , a)){
        stringstream str(a);
        vi coef;
        int n;
        while(str >> n)
            coef.push_back(n);
        getline(cin , a);
        str.clear();
        str.str(a);
        int b = 0;
        while (str >> n){
            int ans = 0;
            for (int i = 0; i < coef.size(); ++i) {
                ans += coef[i] * pow (n , (int)coef.size() - i - 1);
            }
            if (b++) cout << " " ;
            cout << ans ;
        }
        cout << endl;
    }

    return 0;
}

#endif