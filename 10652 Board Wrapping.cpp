//#define Q10652
#ifdef Q10652

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
#define pi acos(-1)

struct point{
    double x,y;
    point(double _x , double _y){ x = _x , y = _y;}
    point() { x = y = 0.0; }
    bool operator < (const point & p) const {  return (x == p.x)? y<p.y : x <p.x ; }
};

struct vec{
    double x,y;
    vec(double X , double Y) { x = X; y = Y; }
};

vec toVec(point a, point b) {return vec(b.x - a.x, b.y - a.y); }


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

double degTorad(double theta) { return theta * pi / 180.0; }

double polygonArea(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        x1 = P[i].x, x2 = P[i + 1].x;
        y1 = P[i].y, y2 = P[i + 1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}


point rotate(point p, point loc, double theta) {
    p.x -= loc.x, p.y -= loc.y;
    double rad = degTorad(theta);
    return point(p.x * cos(rad) - p.y * sin(rad) + loc.x,
              p.x * sin(rad) + p.y * cos(rad) + loc.y);
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        vector<point> vec;
        double x , y , w, h , theta;
        double first = 0;
        for (int i = 0; i < n; i++){
            cin >> x >> y >> w >> h >> theta;
            first += w * h;
            w /= 2; h /= 2;
            vec.push_back(rotate(point(x + w , y + h) , point(x , y) , 360 - theta));
            vec.push_back(rotate(point(x + w , y - h) , point(x , y) , 360 - theta));
            vec.push_back(rotate(point(x - w , y - h) , point(x , y) , 360 - theta));
            vec.push_back(rotate(point(x - w , y + h) , point(x , y) , 360 - theta));
        }
        vector<point>p = convexHull(vec);
        double sec = polygonArea(p);
        cout << fixed << setprecision(1) << first / sec * 100 << " %" << endl;
    }

    return 0;
}

#endif