//#define Q11094
#ifdef Q11094

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvc vec; vvi vis;
int m,n; char key;
int d1[] = {-1 , 1 , 0 , 0} , d2[] = {0 , 0 , -1 , 1};

int dfs(int a , int b){
    if (a < 0 || a  >= m || b  < 0 || b >= n) return 0;
    if ( vis[a][b] || vec[a][b] != key) return 0;
    vis[a][b] = 1;
    int ans = 1;
    for ( int i = 0; i < 8; i++) {
        int tmp = b + d2[i];
        if (tmp == n) tmp = 0;
        else if (tmp == -1) tmp = n - 1;
        ans += dfs(a + d1[i], tmp);
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

    while ( cin >> m >> n) {
        vec.clear();
        vec.resize(m + 2, vc(n + 2));
        vis.clear();
        vis.resize(m + 2, vi(n + 2, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> vec[i][j];
        int a, b, tmp, mx = 0;
        cin >> a >> b;
        key = vec[a][b];
        tmp = dfs(a, b);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (vis[i][j] == 0) {
                    int ans = dfs(i, j);
                    mx = max(ans, mx);
                }
        cout << mx << endl;
    }

    return 0;
}

#endif