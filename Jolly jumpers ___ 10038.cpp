#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int n, num, result,dif;
	vector<int>vec;
	vector<int> check;
	while (cin >> n){
		result = 1;
		for (int i = 0; i < n; i++){
			cin >> num;
			vec.push_back(num);
			check.push_back(i);
		}
		for (int i = 0; i < vec.size() - 1; i++){
			dif = abs(vec[i + 1] - vec[i]);
			if (dif< 1 || dif > n - 1)
				result = 0;
			else
				check[dif]=0;
		}
		for (int i = 0; i < check.size(); i++){
			if (check[i] != 0)
				result = 0;
		}
		if (result)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
		vec.clear();
		check.clear();
	}
	return 0;
}