//#define Q12442
#ifdef Q12442

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi vec, vis , memo;
int num;

int dfs(int u) {
    vis[u] = 1;
    int tmp = 0;
    if (vis[vec[u]] == 0) tmp = 1 + dfs(vec[u]);
    else tmp = 1;
    vis[u] = 0;
    return memo[u] = tmp;
}

int main(){

    ios::sync_with_stdio(0);

    int tc , count = 1; cin >> tc;
    while ( tc-- ){
        int n; cin >> n;
        vec.clear(); vec.resize(n + 1, -1);
        vis.clear(); vis.resize(n + 1, 0);
        memo.clear(); memo.resize(n + 1, 0);
        int a,b;
        int ans = -1;
        int indx;
        for ( int i = 0; i < n; i++){
            cin >> a >> b;
            vec[a-1]=b-1;
        }
        for ( int i = 0; i < n; i++){
            if ( vec[i] != -1 ){
                num = memo[i];
                if (!memo[i]) num = dfs(i);
                if ( num > ans)
                    indx = i , ans = num;
            }
        }
        cout << "Case "<<count++<<": "<<indx+1<<endl;
    }

    return 0;
}

#endif