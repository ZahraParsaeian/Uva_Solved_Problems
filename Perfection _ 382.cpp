#include<iostream>
#include<iomanip>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int n,sum;
	cout << "PERFECTION OUTPUT" << endl;
	while (1){
		cin >> n;
		sum = 0;
		if (n == 0)
			break;
		for (int i = 1; i <= n / 2; i++){
			if (n%i == 0)
				sum += i;
		}
		if (sum == n)
			cout << setw(5) << n << "  " << "PERFECT" << endl;
		else if (sum>n)
			cout << setw(5) << n << "  " << "ABUNDANT" << endl;
		else if (sum < n)
			cout << setw(5) << n << "  " << "DEFICIENT" << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}