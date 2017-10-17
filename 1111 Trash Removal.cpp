//#define Q1111
#ifdef Q1111

//AC
//If u make its convexhull first then its true to find the minimax :))

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
#define EPS 1e-9

struct point{
    double x,y;
    point(double _x , double _y){ x = _x , y = _y;}
    point() { x = y = 0.0; }
    bool operator < (const point & p) const {  return (x == p.x)? y<p.y : x <p.x ; }
};

double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

struct vec{
    double x,y;
    vec(double X , double Y) { x = X; y = Y; }
};

vec toVec(point a, point b) {return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) {return vec(v.x * s, v.y * s); }

point translate(point p, vec v) {return point(p.x + v.x , p.y + v.y); }

double dot (vec a , vec b){ return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b) {
    point c;
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }

vector<point> convexHull(vector<point> P){
    int n = P.size(),k =0; vector<point> H(2*n);
    sort(P.begin(), P.end());
    for( int i =0; i< n; i++){
        while( k>=2 && !ccw(H[k-2], H[k-1] , P[i])) k--; H[k++] = P[i];
    }
    for( int i=n-2, t=k+1; i>=0; i--){
        while( k>=t && !ccw(H[k-2], H[k-1] , P[i])) k--; H[k++] = P[i];
    }
    H.resize(k); return H;
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    int cont = 1;
    while (cin >> n && n) {
        vector<point> p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        vector<point>points = convexHull(p);
        double ans = inf;
        for (int i = 0; i < points.size() - 1; ++i) {
            double mx = -1;
            for (int j = 0; j < points.size(); ++j) {
                if (j == i || j == i + 1) continue;
                mx = max(mx , distToLine(points[j] ,points[i] , points[i + 1]));
            }
            ans = min(ans , mx);
        }
        cout << "Case " << cont++ << ": " ;
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}

#endif