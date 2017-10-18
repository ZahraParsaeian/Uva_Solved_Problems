//#define Q10263
#ifdef Q10263

//AC

#include<iostream>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;

#define EPS 1e9
#define MIN 1e100

struct point{
	double x, y;
	point(){
		x = y = 0.0;
	}
	point(double _x, double _y) :x(_x), y(_y) {}
	bool operator < (point other) const {  
		if (fabs(x - other.x) > EPS) 
			return x < other.x; 
		return y < other.y; 
	} 
};

struct line{
	double a, b, c;
};

struct vec {
	double x, y; 
	vec(double _x, double _y) : x(_x), y(_y) {} 
};

vec toVec(point a, point b) { 
	return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) { 
	return vec(v.x * s, v.y * s); 
} 
point translate(point p, vec v) { 
	return point(p.x + v.x, p.y + v.y);
}
double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) { 
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;  
	} 
	else { 
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x); 
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y; 
	}
}
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b, point &c) { 
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c); 
}

double distToLineSegment(point p, point a, point b, point &c) { 
	vec ap = toVec(a, p), ab = toVec(a, b); 
	double u = dot(ap, ab) / norm_sq(ab); 
	if (u < 0.0) { 
		c = point(a.x, a.y); 
		return dist(p, a); 
	} 
	if (u > 1.0) { 
		c = point(b.x, b.y); 
		return dist(p, b); 
	}  
	return distToLine(p, a, b, c); 
} 

int main(){

	ios::sync_with_stdio(0);

	double x,y;
	int n;
	vector<point>vec;
	point ans,final;
	while (cin >> x){
		double min = MIN;
		cin >> y;
		point pt(x, y);
		cin >> n;
		for (int i = 0; i < n + 1; i++){
			cin >> x >> y;
			vec.push_back(point(x, y));
		}
		for (int i = 0; i < vec.size()-1; i++){
			double dis=distToLineSegment(pt, vec[i], vec[i + 1], ans);
			if (dis < min){
				min = dis;
				final = ans;
			}
		}
		cout << fixed << setprecision(4) << final.x << endl;
		cout << fixed << setprecision(4) << final.y << endl;
	}
	return 0;
}


#endif