//#define Q907
#ifdef Q907

//AC

#include <bits/stdc++.h>

using namespace std;

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
#define inf 1e9
#define sup 1e-9

vvi memo;
int n , k ;
int mx , x;
vi vec;

int go (int cur , int night_left){
    if (night_left == 0) return vec.back() - vec[cur];
    if (memo[cur][night_left] !=  -1) return memo[cur][night_left];
    int ans =inf ;
    for (int i = cur + 1; i < n + 1; ++i) {
            int next = max(go(i, night_left - 1) , vec[i] - vec[cur]);
                ans = min(ans , next);
    }
    return memo[cur][night_left] = ans;
}

int main(){

    ios::sync_with_stdio(0);

    while (cin >> n >> k){
        memo.clear(); memo.resize( n + 2 , vi (k + 1 ,-1));
        vec.clear(); vec.resize( n + 2);
        vec[0] = 0;
        for (int i = 1; i < n + 2; ++i)
            cin >> vec[i];
        for (int i = 1; i < n + 2; ++i)
            vec[i] += vec[i - 1];
        int ans = go(0 , k);
        cout << ans << endl;
    }

    return 0;
}

#endif