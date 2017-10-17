//#define Q216
#ifdef Q216

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<double>vd;
typedef vector<vd>vvd;

int n;
vvd dist;
vvd memo;
vvi path;

double tsp(int pos, int mask) {
    if (mask == (1 << n) - 1) return 0;
    if (memo[pos][mask] != -1) return memo[pos][mask];
    double ans = INT_MAX;
    int indx = -1;
    for (int nxt = 0; nxt < n; ++nxt)
        if (nxt != pos && !(mask & (1 << nxt))) {
            double ch = tsp(nxt, mask | (1 << nxt)) + dist[pos][nxt];
            if (ans > ch)
                ans = ch, indx = nxt;
        }
    path[pos][mask] = indx;
    memo[pos][mask] = ans;
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

    int count=1;
    while(cin>>n && n){
        cout<<"**********************************************************"<<endl<<"Network #"<<count++<<endl;
        memo.clear(); memo.resize(n+1,vd(2048,-1));
        path.clear(); path.resize(n+1,vi(2048));
        vector<pair<int,int>>vec(n);
        for (int i = 0; i < n; ++i)
            cin>>vec[i].first>>vec[i].second;
        dist.clear();  dist.resize(n,vd(n));
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < n; ++i)
                dist[j][i]=hypot(vec[i].first-vec[j].first,vec[i].second-vec[j].second) + 16;
        double mn = INT_MAX; int indx = -1;
        for (int k = 0; k < n; ++k) {
            double val = tsp(k , 1<<k);
            if(val < mn)
                mn = val , indx = k;
        }
        int mask = 0;
        while(--n){
            mask |= (1<<indx);
            cout<<"Cable requirement to connect ("<<vec[indx].first<<","<<vec[indx].second<<") to (" <<vec[path[indx][mask]].first<<","
                <<vec[path[indx][mask]].second<<") is "<<fixed<<setprecision(2)<<dist[indx][path[indx][mask]]<<" feet."<<endl;
            indx = path[indx][mask];
        }
        cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<mn<<".\n";
    }

    return 0;
}

#endif