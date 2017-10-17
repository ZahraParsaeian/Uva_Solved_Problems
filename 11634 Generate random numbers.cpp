//#define Q11634
#ifdef Q11634

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

    int n;
    while (cin >> n && n){
        int cont = 0;
        map<int,int> m;
        while (m[n] == 0){
            m[n] = 1;
            cont ++;
            n = ((n * n) / 100) % 10000;
        }
        cout << cont << endl;
    }

    return 0;
}

#endif