#define Q11504
#ifdef Q11504

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int numSCC, cont;
vi vis,scc,dfs_low,dfs_num,choom;
vvi vec;

void tarjanSCC(int u){
    dfs_num[u] = dfs_low[u] = cont++;
    vis[u] = 1;
    scc.push_back(u);
    for(auto i : vec[u]){
        if ( dfs_num[i] == -1 ) tarjanSCC(i);
        choom[i]--;
        if (vis[i])
            dfs_low[u] = min (dfs_low[u] , dfs_low[i]);
    }
    if (dfs_low[u] == dfs_num[u] ){
        bool add =true;
        while(1){
            int tmp = scc.back();
            scc.pop_back();
            if(choom[tmp] > 0) add = false;
            vis[tmp] = 0;
            if(tmp == u) break;
        }
        if(add)  numSCC++;
    }
}

int main(){

    ios::sync_with_stdio(0);

    int tc , v ,e , a , b; cin >> tc;
    while(tc--){
        cin >> v >> e;
        numSCC = cont = 0;
        vec.clear();      vec.resize(v);
        vis.clear();      vis.resize(v, 0);
        dfs_num.clear();  dfs_num.resize(v, -1);
        dfs_low.clear();  dfs_low.resize(v);
        scc.clear();
        choom.clear(); choom.resize(v , 0);
        for ( int i = 0; i < e; i++){
            cin >> a >> b;
            vec[a-1].push_back(b-1);
            choom[b-1]++;
        }
        for(int i = 0; i < v; i++){
            if (dfs_num[i] == -1)
                tarjanSCC(i) ;
        }
        cout << numSCC << endl;
    }

    return 0;
}

#endif