//#define Q10487
#ifdef Q10487

#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n, m, num, count = 0;
	vector<int>nums;
	int number;
	vector<int>queries;
	while (cin >> n && n){
		nums.clear();
		nums.resize(n);
		cout << "Case " << ++count << ":" << endl;
		for (int i = 0; i< n; i++)
			cin >> nums[i];
		cin >> m;		
		for (int j = 0; j < m; j++){
			cin >> number;
			int min = 1e9; int ans;		
			for (int i = 0; i < nums.size(); i++){
				for (int k = i+1; k <nums.size(); k++){
					if (abs(nums[i] + nums[k] - number)<min){
						min = abs(nums[i] + nums[k] - number);
						ans = nums[i] + nums[k];
					}
				}
			}
			cout << "Closest sum to " << number << " is " << ans << "." << endl;
		}
	}
	return 0;
}

#endif