//#define Q10943
#ifdef Q10943

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi memo;

int ways( int n, int k ) {
    //if (k == 1) return 1;
    if(!n && !k) return 1;
    if(!k) return 0;
    if(n<0) return 0;
    if (memo[n][k] != -1) return memo[n][k];
    int ans = 0;
    for (int j = 0; j <= n; j++)
        ans += ways(n - j, k - 1) , ans %= 1000000;
    return memo[n][k] = ans;
}

int main() {

    ios::sync_with_stdio(0);

    int n, k;
    while (cin >> n >> k && (n || k)) {
        memo.clear();  memo.resize(n + 1, vi(k + 2, -1));
        cout << ways(n, k) << endl;
    }
    return 0;
}

#endif