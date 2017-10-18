#define Q10503
#ifdef Q10503

//AC

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int frs, sec,spc,pic;
vector<pair<int, int>> match;
vector<int>vec;

bool check(int a,int i){
	if (i == spc){
		if (match[a].second == sec)
			return true;
		return false;
	}
	for (int j = 1; j < match.size(); j++){
		if (vec[j] == 0){
			if (match[j].first == match[a].second){
				vec[j] = 1;
				if (check(j, i + 1))
					return true;
				vec[j] = 0;
			}
			else if (match[j].second == match[a].second){
				int change = match[j].second;
				match[j].second = match[j].first;
				match[j].first = change;
				vec[j] = 1;
				if (check(j,i+1))
					return true;
				vec[j] = 0;
			}
		}
	}
	return false;
}

int main(){

	ios::sync_with_stdio(0);

	int f,s,fake,result;
	while (cin >> spc&&spc){
		cin >> pic >> fake >> frs;
		match.push_back(make_pair(fake, frs));
		cin >> sec >> fake;
		vec.resize(pic+2);
		for (int i = 0; i < pic; i++){
			cin >> f >> s;
			match.push_back(make_pair(f, s));
		}
		if (check(0, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
		vec.clear();
		match.clear();
	}
	return 0;
}

#endif