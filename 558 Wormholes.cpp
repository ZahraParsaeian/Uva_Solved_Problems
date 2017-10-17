//#define Q558
#ifdef Q558

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

int n , m;
vvii vec;
vi dist;

void blmnfrd(){
    dist[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto k : vec[j]){
                if(dist[k.second] > dist[j] + k.first)
                    dist[k.second] = dist[j] + k.first;
            }
        }
    }
}

bool check(){
    int exist = false;
    for (int i = 0; i < n; ++i) {
        for (auto j : vec[i]) {
            if (dist[j.second] > dist[i] + j.first)
                return true;
        }
    }
    return false;
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        cin >> n >> m;
        int x , y , t;
        vec.clear(); vec.resize(n);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> t;
            vec[x].push_back(ii(t,y));
        }
        dist.clear(); dist.resize(n , inf);
        blmnfrd();
        if (check()) cout << "possible\n";
        else cout << "not possible\n";
    }

    return 0;
}

#endif