//#define Q10005
#ifdef Q10005

//AC

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
typedef queue<ii> qii;
typedef pair<int , double> id;
typedef vector<id> vid;
typedef vector<vid> vvid;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unsigned long long ull;
typedef pair<double , double > dd;
typedef vector<dd> vdd;
#define inf 1e9
#define sup 1e-9

bool circle2PtsRad(dd p1, dd p2, double r, dd &c) {
    double d2 = pow((p1.first - p2.first) , 2) + pow((p1.second - p2.second) , 2);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.first = (p1.first + p2.first) * 0.5 + (p1.second - p2.second) * h;
    c.second = (p1.second + p2.second) * 0.5 + (p2.first - p1.first) * h;
    return true;
}

int insideCircle(dd p, dd c, double r) {
    double dx = p.first - c.first, dy = p.second - c.second;
    double Euc = dx * dx + dy * dy, rSq = r * r;
    return rSq - Euc > sup ? 0 : (fabs(Euc - rSq) < sup ? 1 : 2);
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n) {
        vdd vec(n);
        double r;
        for (int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;
        cin >> r;
        bool fnd = false;
        for (int i = 0; i < n && !fnd; ++i)
            for (int j = 0; j < n && !fnd; ++j) {
                if (i == j) continue;
                dd cnt;
                if (circle2PtsRad(vec[i], vec[j], r, cnt))
                    for (int d = 0; d < n; d++) {
                        if (insideCircle(vec[d], cnt, r) == 2) break;
                        if (d == n - 1) fnd = true;
                    }
            }
        if(fnd) cout << "The polygon can be packed in the circle.\n";
        else cout << "There is no way of packing that polygon.\n";
    }
    return 0;
}

#endif