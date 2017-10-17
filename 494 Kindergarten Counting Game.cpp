//#define Q494
#ifdef Q494

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
    while (getline(cin , a)){
        int cont = 0;
        for (int i = 0; i < a.size(); i++){
            if (isalpha(a[i])) cont++;
            while (isalpha(a[i])) i++;
        }
        cout << cont << endl;
    }

    return 0;
}

#endif