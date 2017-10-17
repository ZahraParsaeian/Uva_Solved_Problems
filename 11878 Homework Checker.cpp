//#define Q11878
#ifdef Q11878

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

    int a , b ;
    char d , e ;
    string c;
    int cont = 0;
    while (cin >> a >> d >> b >> e >> c) {
        if (c != "?") {
            int p = 1;
            int ans = 0;
            for (int i = c.size() -1 ; i >= 0; i--)
                ans += p * (c[i] - '0') , p *= 10;
            if (d == '-') {
                if (ans == a - b)
                    cont++;
            } else {
                if (ans == a + b)
                    cont++;
            }
        }
    }
    cout << cont << endl;


    return 0;
}

#endif