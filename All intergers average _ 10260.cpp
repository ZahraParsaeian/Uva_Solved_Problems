#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int tedad(int a){
	int cont = 0;
	while (a != 0){
		a /= 10;
		cont++;
	}
	return(cont);
}

int main(){

	ios::sync_with_stdio(false);
	int n,sum,num,s,m,size,rest,nn,ss,kharej,cont=0,result;
	while (1){
		sum = 0;
		rest = -1;
		result = 0;
		size = 0;
		cin >> n;
		cont++;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++){
			cin >> num;
			sum += num;
		}
		if (sum < 0){
			sum = -sum;
			size += 2;
			result = 1;
		}
		s = sum%n;
		m = sum / n;
		if (s != 0){
			ss = s;
			nn = n;
			while (rest != 0){
				rest = nn%ss;
				kharej = nn / ss;
				nn = ss;
				ss = rest;
			}
				n /= nn;
				s /= nn;
			size += tedad(n);
			if (m!=0)
				size += tedad(m);
			cout << "Case " << cont << ":" << endl
				<< setw(size) << s << endl;
			if (result)
				cout << "- ";
			if (m!=0)
				cout << m;
			for (int j = 0; j < ((n / 10) + 1); j++)
				cout << "-";
			cout << endl;
			cout << setw(size) << n << endl;
		}
		else{
			cout << "Case " << cont << ":" << endl;
			if (result)
				cout << "- ";
			cout << m << endl;
		}
	}
	cout << endl;
	return 0;
}