//#define Q12047
#ifdef Q12047

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
typedef vector<vii> vvii;
#define inf 1e9
#define sup 1e-9

int n , m  , p;
vi dists , distt;

void dijkstra(int s , vi &dist , vvii &vec) {
    priority_queue<ii , vii , greater<ii>> q;
    dist.clear(); dist.resize(n , inf);
    q.push(ii(0, s));
    dist[s] = 0;
    while (!q.empty()) {
        ii a = q.top();
        q.pop();
        if (a.first > dist[a.second]) continue;
        for (auto i : vec[a.second]) {
            if (dist[a.second] + i.first < dist[i.second]) {
                dist[i.second] = dist[a.second] + i.first;
                q.push(make_pair(i.first, i.second));
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int s, t;
        cin >> n >> m >> s >> t >> p;
        vvii vecs(n) , vect(n);
        int a, b, c;
        viii edge;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            a-- ; b--;
            vecs[a].push_back(ii(c, b));
            vect[b].push_back(ii(c, a));
            edge.push_back(make_pair(c , ii ( a , b )));
        }
        s--;
        t--;
        dijkstra( s , dists , vecs);  dijkstra( t , distt, vect);
        int mx = -1;
        for (auto i : edge) {
            if (dists[i.second.first]  + distt[i.second.second] + i.first <= p)
                mx = max (mx ,  i.first);
        }
        cout  << mx << endl;
    }

    return 0;
}

#endif