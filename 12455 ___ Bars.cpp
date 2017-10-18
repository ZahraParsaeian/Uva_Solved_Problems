#include<iostream>
#include<vector>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int tc,length,nubar,bars,sum,result;
	vector<int>vec;
	cin >> tc;
	while (tc--){
		result = 0;
		cin >> length>>nubar;
		for(int i=0;i<nubar;i++){
			cin >> bars;
			vec.push_back(bars);
		}
		for (int i = 0; i < (1 << nubar); i++){
			sum = 0;
			for (int j = 0; j < nubar; j++){
				if (i & (1 << j)){
					sum += vec[j];
				}
				if (sum == length)
					result = 1;
			}
		}
		if (result)
			cout << "YES\n";
		else
			cout << "NO\n";	
		vec.clear();
	}
	return 0;
}
