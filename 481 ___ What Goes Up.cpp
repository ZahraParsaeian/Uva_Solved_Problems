#define Q481
#ifdef Q481

//AC

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	ios::sync_with_stdio(0);

	vector<long long>vec;
	int n;
	while (cin >> n)
		vec.push_back(n);
	int ans = 0;
	vector<long long>check;
	check.resize(vec.size());
	vector<long long>b;
	b.resize(vec.size());
	for (int i = 0; i < vec.size(); i++){
		int c = lower_bound(check.begin(), check.begin()+ans+1, vec[i]) - check.begin();
		check[c] = vec[i];
		b[i] = c;
		ans = max(c, ans);
	}
	vector<long long>answer;
	for (int i = vec.size() - 1; i >= 0; i--){
		if (b[i] == ans){
			answer.push_back(vec[i]);
			ans--;
		}
	}
	cout << answer.size() << endl << "-\n";
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++){
		cout << answer[i] << endl;
	}
	return 0;
}

#endif