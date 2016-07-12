#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int n, cont = 0, result,yes, d = 0,rest,taghsim,ss,ff;
	long int num,f,s;
	set<long int>Map;
	vector<set<long int>>vec;
	while (1){
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++){
			cin >> num;
			Map.insert(Map.end(), num);
		}
		vec.push_back(Map);
		Map.clear();
	}
	for (int i = 0; i < vec.size();i++){
		cout << "Case " << i+1 << ":" << endl;
		set<long int>::iterator first;
		set<long int>::iterator second;
		second = vec[i].begin();
		while (second != vec[i].end()){
			yes = 0;
			result = 1;
			first = second;
			f = *first;
			while (result){
				first = second;
				second++;
				if (second != vec[i].end()){
					if ((*first + 1) != *second)
						result = 0;
					else{
						s = *second;
						yes = 1;
					}
				}
				else
					result = 0;
			}
			if (yes){
				taghsim = 10;
				ff = f/taghsim;
				ss = s/taghsim;
				while (ff != ss){
					taghsim *= 10;
					ff = f / taghsim;
					ss = s / taghsim;
				}
				rest = s % taghsim;
				cout  << 0 << f << "-" << rest << endl;
			}
			else
				cout  << 0 << f << endl;

		}
		cout << endl;
	}
	return 0;
}