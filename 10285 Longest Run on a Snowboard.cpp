//#define Q10285
#ifdef Q10285

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

vvi dp;
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0 , 1 , 0 , -1 };
vvi vec;
int row , col;

int dfs (int i , int j){
    if (dp[i][j] != -1) return dp[i][j];
    int mx = 0;
    for (int k = 0; k < 4; ++k)
        if (i + dx[k] >= 0 && i + dx[k] < row && j + dy[k] >= 0 && j + dy[k] < col)
            if (vec[i][j] > vec[i + dx[k]][j + dy[k]])
                mx = max (mx , dfs(i + dx[k] , j + dy[k]) + 1);
    dp[i][j] = mx;
    return mx;
}

int main(){
    
    ios::sync_with_stdio(0);
    
    int tc; cin >> tc;
    while (tc--) {
        string a; cin >> a;
        cin >> row >> col;
        dp.clear(); dp.resize(row , vi (col , -1));
        vec.clear(); vec.resize(row , vi (col));
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) 
                cin >> vec[i][j] , dp[i][j] = -1;
        int ans = -1;
        for (int i = 0; i < row; ++i) 
            for (int j = 0; j < col; ++j) 
                ans = max (ans , dfs (i , j));
        cout << a << ": " << ans  + 1<< endl;

    }
    
    return 0;
}

#endif