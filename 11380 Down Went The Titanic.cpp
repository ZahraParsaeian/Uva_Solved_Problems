//#define Q11380
#ifdef Q11380

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

vvc v;
vvi adj , res;
vvi w;
vi p;
mii m;
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
int f, mf;
int n;

void aug(int v , int mineg){
    if(v == 0){
        f = mineg;
        return ;
    }
    else if(p[v] != -1){
        aug(p[v] , min(mineg , res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

void edmokar(){
    mf = 0;
    while(1){
        f = 0;
        vector<bool> vis(n + 1 , false); vis[0] = true;
        p.clear(); p.resize(n + 1 , -1);
        qi q; q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if ( u == n ) break;
            for (auto i : adj[u]){
                if(res[u][i] > 0 && !vis[i])
                    vis[i] = true , q.push(i) , p[i] = u;
            }
        }
        aug(n, inf);
        if (f == 0) break;
        mf += f;
    }
}


int main(){

    ios::sync_with_stdio(0);

    int x,y,p;
    vvi mp(210 , vi(210 , 0));
    mp['.']['.'] = mp['.']['@'] = mp['.']['#'] = 1;
    mp['*']['.'] = mp['*']['@'] = mp['*']['#'] = 1;
    mp['@']['@'] = mp['@']['#'] = inf; mp['@']['.'] = 1;
    mp['#']['#'] = inf; mp['#']['@'] = inf; mp['#']['.'] = 1;
    while (cin >> x >> y >> p) {
        v.clear(); v.resize(x, vc (y));
        w.clear(); w.resize(x , vi (y));
        n = 2 * x * y + 1;
        res.clear(); res.resize(2 * x * y + 2 , vi (2 * x * y + 2));
        adj.clear(); adj.resize(2 * x * y + 2 , vi (2 * x * y + 2));
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j) {
                cin >> v[i][j];
                if (v[i][j] != '~') {
                    adj[i * y + j + x * y + 1].push_back(i * y + j + 1);
                    adj[i * y + j + 1].push_back(i * y + j + x * y + 1);

                    if (v[i][j] == '*') {
                        res[0][i * y + j + 1] = 1;
                        adj[0].push_back(i * y + j + 1);
                        adj[i * y + j + 1].push_back(0);
                        res[i * y + j + 1][i * y + j + x * y + 1] = 1;

                    } else if (v[i][j] == '#') {
                        res[i * y + j + x * y + 1][2 * x * y + 1 ] = p;
                        adj[i * y + j + x * y + 1].push_back(2 * x * y + 1 );
                        adj[2 * x * y + 1].push_back(i * y + j + x * y + 1);
                        res[i * y + j + 1][i * y + j + x * y + 1] = 1000;
                    } else if (v[i][j] == '.')
                        res[i * y + j + 1][i * y + j + x * y + 1] = 1;
                    else if (v[i][j] == '@')
                        res[i * y + j + 1][i * y + j + x * y + 1] = 1000;
                }
            }
        int dx[] = { -1 , 0 , 1 , 0 } , dy[] = { 0 , 1 , 0 , -1 };
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                for (int k = 0; k < 4; ++k)
                    if (i + dx[k] >= 0 && i + dx[k] < x && j + dy[k] >= 0 && j + dy[k] < y)
                        if (mp[v[i][j]][v[i + dx[k]][j + dy[k]]]){
                            res[i * y + j + x * y + 1][(i + dx[k] )* y + j + dy[k] + 1] = mp[v[i][j]][v[i + dx[k]][j + dy[k]]];
                            adj[(i + dx[k] )* y + j + dy[k] + 1].push_back(i * y + j + x * y + 1);
                            adj[i * y + j + x * y + 1].push_back((i + dx[k] )* y + j + dy[k] + 1);
                        }
        edmokar();
        cout << mf << endl;
    }

    return 0;
}

#endif