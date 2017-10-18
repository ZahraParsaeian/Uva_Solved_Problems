//#define Q10407
#ifdef Q10407

#include<iostream>
#include<math.h>

using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int a, b,ans;
	while (cin >> a && a){
		ans = 0;
		while (cin >> b && b){
			b -= a;
			ans = gcd(ans, b);
		}
		cout << abs(ans) << endl;
	}
	return 0;
}


#endif