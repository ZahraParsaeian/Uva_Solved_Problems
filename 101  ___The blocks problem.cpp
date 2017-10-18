#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>>vec;
int second;

int find(int s){
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < vec[i].size(); j++){
			if (vec[i][j] == s){
				second = j;
				return i;
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(false);

	int n, go, on;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
		vec[i].push_back(i);
	string frs, sec;
	while (cin >> frs && frs != "quit"){
		cin >> go >> sec >> on;
		if (frs == "move"){
			if (sec == "onto"){
				int s, kk = 0, ss;
				s = find(on);
				if (second != vec[s].size() - 1)
					kk = second + 1;
				ss = find(go);
				if (s != ss){
					if (kk != 0){
						for (int l = kk; l < vec[s].size(); l++)
							vec[vec[s][l]].insert(vec[vec[s][l]].begin(), vec[s][l]);
					}
					vec[s].push_back(go);
					if (second != vec[ss].size() - 1){
						for (int k = second + 1; k < vec[ss].size(); k++)
							vec[vec[ss][k]].insert(vec[vec[ss][k]].begin(), vec[ss][k]);
					}
					vec[ss].erase(vec[ss].begin() + second, vec[ss].end());
				}
				else
					break;
			}
			else if (sec == "over"){
				int s, ss;
				s = find(on);
				ss = find(go);
				if (s != ss){
					if (second != vec[ss].size() - 1){
						for (int k = second + 1; k < vec[ss].size(); k++)
							vec[vec[ss][k]].insert(vec[vec[ss][k]].begin(), vec[ss][k]);
					}
					vec[ss].erase(vec[ss].begin() + second, vec[ss].end());
					vec[s].insert(vec[s].end(), go);
				}
				else
					break;
			}
		}
		else if (frs == "pile"){
			if (sec == "onto"){
				int s, ss, kk = 0;
				s = find(on);
				if (second != vec[s].size() - 1)
					kk = second + 1;
				int ajab = 0;
				ss = find(go);
				if (s != ss){
					for (int k = second; k < vec[ss].size(); k++){
						if (kk != 0 && ajab == 0){
							for (int l = kk; l < vec[s].size(); l++)
								vec[vec[s][l]].insert(vec[vec[s][l]].begin(), vec[s][l]);
							ajab = 1;
							vec[s].erase(vec[s].begin() + kk, vec[s].end());
						}
						vec[s].push_back(vec[ss][k]);
					}
					vec[ss].erase(vec[ss].begin() + second, vec[ss].end());
				}
				else
					break;
			}
			else if (sec == "over"){
				int s = find(on), result = 0;
				int ss = find(go);
				for (int k = second; k < vec[ss].size(); k++){
					if (s != ss)
						vec[s].push_back(vec[ss][k]);
					else{
						break;
					}
				}
				vec[ss].erase(vec[ss].begin() + second, vec[ss].end());
			}
		}
	}
	for (int i = 0; i < vec.size(); i++){
		cout << i << ": ";
		for (int j = 0; j < vec[i].size(); j++){
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}