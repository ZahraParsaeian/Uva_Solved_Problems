//#define Q11207
#ifdef Q11207

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
typedef pair<double , double > dd;
typedef vector<dd> vdd;
#define inf 1e9
#define sup 1e-9

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n){
        double a , b ,tmp;
        double mx = -1 ;
        int indx;
        for (int i = 1; i <= n; i++){
            cin >> a >> b;
            tmp = a;
            a = min (tmp , b);
            b = max(tmp , b);
            double ans = max (min(a , b / 4) , min (a / 2 , b / 2));
            if (ans > mx) mx = ans , indx  = i;
        }
        cout << indx << endl;
    }

    return 0;
}



#endif