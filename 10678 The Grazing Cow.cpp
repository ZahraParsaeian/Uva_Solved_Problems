//#define Q10678
#ifdef Q10678

//AC

#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

#define pi 2*acos(0)
double l, d;

double b(){
	return sqrt((l*l / 4) - (d*d / 4));
}

int main(){

	ios::sync_with_stdio(0);

	int tc;
	
	cin >> tc;
	while (tc--){
		cin >> d >> l;
		cout << fixed<< setprecision(3) <<pi*(l / 2)*b() << endl;
	}
}


#endif