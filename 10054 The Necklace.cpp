//#define Q10054
#ifdef Q10054

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

vvii vec;
list<ii> cyc;

void EulerTour(list<ii>::iterator i, int u) {
    for (int j = 0; j < (int)vec[u].size(); j++) {
        ii &v = vec[u][j];
        if (v.second) {
            v.second = 0;
            for (int k = 0; k < (int)vec[v.first].size(); k++) {
                ii &uu = vec[v.first][k];
                if (uu.first == u && uu.second) {
                    uu.second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i , ii(u , v.first)), v.first);
        }
    }
}
using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc , n , cont = 1; cin >> tc;
    while (tc--){
        cin >> n;
        vec.clear(); vec.resize(51);
        int a, b;
        vi w(50);
        int what;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            what = a;
            vec[a].push_back(ii(b , 1));
            vec[b].push_back(ii(a , 1));
        }
        int even = 0 , odd = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].size()) {
                if (vec[i].size() % 2 == 0) even++;
                else odd++;
            }
        }
        cout <<"Case #"<<cont++<<endl;
        if (odd)
            cout <<"some beads may be lost\n";
        else{
            cyc.clear();
            EulerTour(cyc.begin(), 0);
            for (auto it = cyc.rbegin(); it != cyc.rend(); it++)
                cout << (*it).first <<" " << (*it).second<< endl;
        }
        if (tc) cout << endl;

    }

    return 0;
}

#endif