//#define Q991
#ifdef Q991

//AC

#include<iostream>

using namespace std;

long long factorial(int a){
	if (a <= 1)
		return 1;
	else
		return a*factorial(a - 1);
}

int main(){

	ios::sync_with_stdio(0);

	int n,cont=0;
	while (cin >> n){
		if (cont != 0)
			cout << endl;
		long long j = (factorial(2 * n) / (factorial(n)*factorial(n)*(n + 1)));
		cout << j << endl;
		cont++;
	}
	return 0;
}

#endif