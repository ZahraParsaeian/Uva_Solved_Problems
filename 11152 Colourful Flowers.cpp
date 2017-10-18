//#define Q11152
#ifdef Q11152

//AC

#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

#define pi acos(-1.0)

int a, b, c;

double perimeter(){
	return (a + b + c);
}

double area(){
	double s = perimeter()/ 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

double rInCircle(){
	return area() / (0.5*perimeter());
}

double rOutCircle(){
	return (a*b*c) / ((4 * area()));
}
int main(){

	ios::sync_with_stdio(0);

	double violet, sun, rose;
	while (cin >> a >> b >> c){
		//cerr<<
		violet = area();
		sun = rOutCircle()*rOutCircle()*pi;
		rose = rInCircle()*rInCircle()*pi;
		sun -= violet;
		violet -= rose;
		cout << fixed << setprecision(4) << sun << " " << violet << " " << rose << endl;
	}
	return 0;
}


#endif