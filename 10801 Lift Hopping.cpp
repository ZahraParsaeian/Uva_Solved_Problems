//#define Q10801
#ifdef Q10801

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

int n , k;
vvii vec;

vi dist;

int dijkstra() {
    priority_queue<ii , vii , greater<ii>> q;
    dist.clear(); dist.resize(100 , inf);
    q.push(ii(0, 0));
    dist[0] = 0;
    while (!q.empty()) {
        ii a = q.top();
        q.pop();
        if (a.second == k) return dist[k];
        if (a.first > dist[a.second]) continue;
        for (auto i : vec[a.second]) {
            if (dist[i.second] > dist[a.second] + i.first + 60) {
                dist[i.second] = dist[a.second] + i.first + 60;
                q.push(ii(dist[i.second], i.second));
            }
        }
    }
    return dist[k];
}

int main(){

    ios::sync_with_stdio(0);

    while (cin >> n >> k){
        vi speed(n);
        vec.clear(); vec.resize(100);
        for (int i = 0; i < n; ++i)
            cin >> speed[i];
        string a , chert;
        getline(cin , chert);
        map <int , int > m;
        for ( int i = 0; i < n; i++) {
            getline(cin, a);
            stringstream str(a);
            int num;
            vi tmp;
            while (str >> num)
                tmp.push_back(num), m[num] = 1;
            for (int ii = 0; ii < tmp.size(); ii++) {
                for (int j = ii + 1; j < tmp.size() ; j++) {
                    vec[tmp[ii]].push_back(make_pair(speed[i] * (tmp[j] - tmp[ii]), tmp[j]));
                    vec[tmp[j]].push_back(make_pair(speed[i] * (tmp[j] - tmp[ii]), tmp[ii]));
                }
            }
        }
        int ans = dijkstra();
        if(ans != inf) {
            if (k != 0)
                ans -= 60;
            cout << ans << endl;
        }

        else  cout << "IMPOSSIBLE\n";

    }

    return 0;
}

#endif