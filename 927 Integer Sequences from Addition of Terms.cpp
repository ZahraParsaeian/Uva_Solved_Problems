#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int tc,coe;
	double isSame;
	long long int sum,which,n,check,divide,k,num,d;
	cin >> tc;
	string chert, nums;
	getline(cin, chert);
	while (tc--){
		coe = sum = 0;
		getline(cin, nums);
		cin >> d >> k;
		divide = (k / d)*2;
		isSame = sqrt(1 + (4 * divide));
		check = sqrt(1 + (4 * divide));
		which = sqrt(1 + (4*divide));
		which++;
		which /= 2;
		if (isSame == check && k%d == 0)
			which--;
		stringstream ss(nums);
		ss >> num;
		while (ss >> num){
			n = num;
			for (int i = 0; i < coe; i++){
				n *= which;
			}
			sum += n;
			coe++;
		}
		cout  <<sum << endl;
		getline(cin, chert);
	}
	return 0;
}