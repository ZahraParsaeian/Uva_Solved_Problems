//#define Q11080
#ifdef Q11080

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;

vvi vec; vi color; bool ok;

int check(int u){
    qi q; q.push(u);
    color[u] = 0;
    int ans = 1 , tmp = 1;
    bool ok = true;
    while( !q.empty() && ok){
        int u = q.front(); q.pop();
        for (int i = 0; i < vec[u].size(); i++){
            if ( color[vec[u][i]] == -1) {
                color[vec[u][i]] = 1 - color[u];
                tmp++;
                if(color[vec[u][i]] == 0) ans++;
                q.push(vec[u][i]);
            }
            else if ( color[vec[u][i]] == color[u]){
                ok = false;
                break;
            }
        }
    }
    if ( !ok ) return -1;
    return min(ans , tmp - ans);
}

int main(){

    ios::sync_with_stdio(0);

    int tc , v, e; cin >> tc;
    while( tc-- ){
        cin >> v >> e;
        vec.clear();  vec.resize(v+1);
        for ( int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int ans = 0;
        color.clear(); color.resize(v+1 , -1);
        for ( int i = 0; i < v; i++) {
            if (color[i] == -1) {
                int tmp = check(i);
                if ( tmp == -1){
                    ans = -1;
                    break;
                }
                if ( tmp ) ans += tmp;
                else ans += 1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}

#endif