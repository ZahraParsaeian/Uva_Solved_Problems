#include<iostream>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int n,cont,i,num,rest;
	while (1){
		cin >> n;
		cont = 0;
		num = 1;
		if (n == 0)
			break;
		while (cont != n){
			while (1){
				i = num;
				while (i % 2 == 0){
					rest = i % 2;
					i /= 2;
				}
				while (i % 3 == 0){
					rest = i % 2;
					i /= 3;
				}
				while (i % 5 == 0){
					rest = i % 2;
					i /= 5;
				}
				while (i % 7 == 0){
					rest = i % 2;
					i /= 7;
				}
				if (rest == 0)
					cont++;
				if (cont==n)
					cout<<
			}
		}

	}
}