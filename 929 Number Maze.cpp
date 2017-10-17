//#define Q929
#ifdef Q929

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
#define inf 1e9

int n , m;
vi dist;
vviii vec;
priority_queue<ii , vii , greater<ii>> q;

void dijkstra(){
    q.push(ii(0, 0));
    while(!q.empty()){
        ii a = q.top(); q.pop();
        if (a.first  > dist[a.second]) continue;
        for (auto i : vec[a.second]){
            if (dist[a.second] + i.first < dist[i.second.first * m + i.second.second]) {
                dist[i.second.first * m + i.second.second] = dist[a.second] + i.first;
                q.push(ii(dist[i.second.first * m + i.second.second] , i.second.first * m + i.second.second));
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        cin >> n >> m;
        dist.clear(); dist.resize(m*n , inf); dist[0] = 0;
        vec.clear(); vec.resize(n * m);
        vvi v(n , vi(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> v[i][j];


        for (int i =0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 < m)
                    vec[i * m + j].push_back(make_pair(v[i][j + 1], make_pair(i, j + 1)));
                if (i + 1 < n)
                    vec[i * m + j].push_back(make_pair(v[i + 1][j], make_pair(i + 1, j)));
                if( j - 1 >= 0)
                    vec[i * m + j].push_back(make_pair(v[i][j - 1], make_pair(i, j - 1)));
                if (i - 1 >= 0)
                    vec[i * m + j].push_back(make_pair(v[i - 1][j], make_pair(i - 1, j)));
            }
        }
        dijkstra();
        cout << dist[n * m - 1] + v[0][0] << endl;
    }

    return 0;
}

#endif