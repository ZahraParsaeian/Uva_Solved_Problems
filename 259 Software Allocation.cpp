//#define Q259
#ifdef Q259

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvd> vvvd;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef  stack<int> si;
typedef queue<int> qi;
#define inf 1e9
#define sup 1e-9

vvi adj , res;
vi p;
int f , mf;

void aug(int v , int mineg){  // baray peida kardn gloogah
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
        vector<bool> vis(38 , false); vis[0] = true;
        p.clear(); p.resize(38 , -1);
        qi q; q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if ( u == 37 ) break;
            for (auto i : adj[u]){
                if(res[u][i] > 0 && !vis[i])
                    vis[i] = true , q.push(i) , p[i] = u;
            }
        }
        aug(37 , inf);
        if (f == 0) break;
        mf += f;
    }
}

int main(){

    ios::sync_with_stdio(0);

    string m;
    while (getline(cin , m)){
        adj.clear(); adj.resize(38);
        res.clear(); res.resize(38 , vi(38));
        int sum = 0 ;
        string c , mm;
        for (int i = 27; i < 37; ++i) {
            adj[i].push_back(37);
            adj[37].push_back(i);
            res[i][37] = 1;
        }
        while(m.length()){
            stringstream str(m);
            str >> mm;
            str >> c;
            char a = mm[0];
            int num = mm[1] - '0';
            sum += num;
            res[0][a - 64] = num;
            adj[0].push_back(a - 64);
            adj[a - 64].push_back(0);
            for (int i = 0; i < c.size() - 1; ++i) {
                adj[a - 64].push_back(c[i] - 48 + 27);
                adj[c[i] - 48 + 27 ].push_back(a- 64);
                    res[a - 64][c[i] - '0' + 27] = 1;

            }
            getline(cin , m);
        }
        edmokar();
        if(mf == sum){
            for (int i = 27; i < 37; ++i) {
                bool ok = false;
                for (int j = 1; j < 27; ++j) {
                    if(res[i][j]){
                        cout << char(j + 64);
                        ok = true;
                        break;
                    }
                }
                if(!ok) cout << "_";
            }
        }
        else cout <<"!";
        cout << endl;
    }

    return 0;
}

#endif