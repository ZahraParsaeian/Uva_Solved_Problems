//#define Q11475
#ifdef Q11475

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

string T, P;
// T = text, P = pattern
int n, m , ans;
vi b;

void kmpPreprocess() {
    b.assign(n + 1, 0);
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j; // observe i = 8, 9, 10,
    }
}

void kmpSearch() {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if (i == n) ans = j;
    }
}

int main(){

    ios::sync_with_stdio(0);

    while (cin >> T){
        P.clear();
        for (int i = T.size() - 1; i >= 0; i--)
            P += T[i];
        n = m = T.size();
        kmpPreprocess(); kmpSearch();
        for (int i = ans; i < P.size(); i++) T+= P[i];
        cout << T << endl;
    }

    return 0;
}

#endif