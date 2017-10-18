#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int tc,cont=1,s,nice,sum=0,result=0;
	vector<int>vec;
	map<int, pair<int, int>>max;
	cin >> tc;
	while (tc--){
		int first, sec;
		result = 0;
		sum = 0;
		cin >> s;
		s--;
		while (s--){
			cin >> nice;
			vec.push_back(nice);
		}
		for (int i = 0; i < vec.size(); i++){
			if (vec[i]<0 && sum>0){
				if (!max.count(sum) || max[sum].first == first||(max.count(sum) == 1 && ((max[sum].second - max[sum].first)<(sec - first))))
					max[sum] = make_pair(first, sec);
			}
			sum += vec[i];
			if (sum>=0){
				if (!result){
					result = 1;
					first = i;
					sec = i;
					if (i == vec.size() - 1){
						sec = i;
						if (!max.count(sum) || max[sum].first == first||(max.count(sum)==1&&((max[sum].second-max[sum].first)<(sec-first))))
							max[sum] = make_pair(first, sec);
					}

				}
				else{
					sec = i;
					if (i == vec.size() - 1){
						if (!max.count(sum) || max[sum].first == first || (max.count(sum) == 1 && ((max[sum].second - max[sum].first)<(sec - first))))
							max[sum] = make_pair(first, sec);
					}
				}

			}
			else{
				sum = 0;
				result = 0;
			}
		}
		map<int, pair<int, int>>::iterator it;
		if (max.size() != 0){
			it = max.end();
			it--;
			cout << "The nicest part of route " << cont << " is between stops " << it->second.first + 1 << " and " << it->second.second + 2 << endl;
		}
		else
			cout << "Route "<< cont<<" has no nice parts\n";
		vec.clear();
		max.clear();
		cont++;
	}
	return 0;
}