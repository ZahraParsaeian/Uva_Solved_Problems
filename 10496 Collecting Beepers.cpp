//#define Q10496
#ifdef Q10496
//
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii>vii;

vii vec;
vvi dist , memo;
int n;

int tsp ( int pos , int mask){
    if(mask == (1 << (n + 1)) - 1)  return dist[pos][0];
    if(memo[pos][mask] != -1) return memo[pos][mask];
    int ans = INT_MAX;
    for( int nxt = 0; nxt < n + 1; nxt++){
        if(nxt != pos && !(mask & (1 << nxt)))
            ans = min(ans , tsp ( nxt , mask | (1 << nxt)) + dist[pos][nxt]);
    }
    return memo[pos][mask] = ans;
}

int main(){

    ios::sync_with_stdio(0);

    int tc;  cin >> tc;
    while(tc--){
        int a1,a2;  cin >> a1 >> a2;
        vec.clear();
        int a,b;
        cin>>a>>b;
        vec.push_back(make_pair(a-1,b-1));
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            vec.push_back(make_pair(a-1,b-1));
        }
        dist.clear(); dist.resize(vec.size(),vi(vec.size()));
        for (int j = 0; j < vec.size(); ++j)
            for (int i = 0; i < vec.size(); ++i)
                dist[i][j] = abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second);
        memo.clear();  memo.resize(11 ,vi(2048,-1));
        cout<<"The shortest path has length "<<tsp(0,1)<<endl;
    }

    return 0;
}

#endif