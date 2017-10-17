//#define Q10203
#ifdef Q10203

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

map<pair<int,int> , int > mp1;
map<int ,ii> mp2;
list<ii> cyc;
vvi vec;
vvi v;

void EulerTour(list<ii>::iterator i, int u) {
    for (auto j : vec[u]) {
        if (v[u][j]) {
            v[u][j] = 0;
            for (auto k : vec[j]) {
                if (k == u && v[j][k]) {
                    v[j][k] = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i , ii(u , j)), j);
        }
    }
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--) {
        int x, y;
        cin >> x >> y;
        vec.clear(); vec.resize(101);
        v.clear(); v.resize(101 , vi (101));
        string a;
        getline(cin , a);
        double sum = 0;
        while(getline(cin , a) && a.length()){
            stringstream str(a);
            int x1 , y1 , x2 , y2;
            str >> x1; str >> y1; str >> x2; str >> y2;
            sum += 2 * hypot(x1 - x2 , y1 - y2);
        }
        sum /= 20000;
        int hour = floor(sum);
        sum -= hour;
        sum *= 60;
        int min = floor(sum);
        sum -= min;
        if (sum > 0.5) min++;
        if (min >= 60) hour++ , min -= 60;
        cout << hour << ":"<<setw(2)<<setfill('0')<<min<<endl;
        if(tc) cout << endl;
    }


    return 0;
}

#endif