//#define Q920
#ifdef Q920

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
#define inf 1e9
#define sup 1e-9

struct point{
    double x , y;
    point (double _x , double _y){ x = _x; y = _y; }
    point (){ x = y = 0.0; }
    bool operator < (point other){
        if (fabs(x - other.x) > sup)
            return x < other.x;
        return y < other.y;
    }
};

double dist(point p1 , point p2){
    return hypot(p1.x - p2.x , p1.y - p2.y);
}

struct line{
    double a, b , c;
    line (double _a , double _b , double _c){ a = _a , b = _b , c = _c; }
    line(){ a = b = c = 0.0; }
};

double retx(line l , double y){
    return (-(l.b * y + l.c) / l.a);
}

void makeline(point p1 , point p2 , line &l){
    if (fabs(p1.x - p2.x) < sup)
        l.a = 1, l.b = 0 , l.c = -p1.x;
    else{
        l.a = -(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1;
        l.c = -(l.a * p1.x) - p1.y ;
    }

}


int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        vector<point> vec(n);
        for (int i = 0; i < n; ++i)
            cin >> vec[i].x >> vec[i].y;
        sort(vec.rbegin(), vec.rend());
        point p(0, 0);
        double pre;
        if (vec.size())
            pre = vec[0].y;
        double sum = 0;
        int cont = 0;
        while (cont < vec.size()){
            while (vec[cont] . y <= pre && cont < vec.size())
                cont++;
            if (cont < vec.size()) {
                line l;
                makeline(vec[cont], vec[cont - 1], l);
                double x = retx(l , pre);
                sum += dist(point(x, pre) , vec[cont]);
            }
            pre = vec[cont].y;
            cont ++;
        }
        cout << fixed << setprecision(2) << sum << endl;

    }

    return 0;
}

#endif