#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	int n, adad, adad1, ah, cont;
	vector<int>vec, ans;
	map<int, int>next;
	map<int, vector<int>>result;
	while (cin >> n){
		vec.push_back(n);
	}
	ah = vec[0];
	next[vec[0]] = 0;
	for (int i = 1; i < vec.size(); i++){
		if (vec[i] < ah){
			next[vec[i]] = i;
			ah = vec[i];
		}
	}
	map<int, int>::iterator i;
	//i = next.begin();
	i = next.end();
	i--;
	while (i != next.begin()){
		adad = i->first;
		ans.push_back(i->first);
		cont = 1;
		int j = i->second + 1;
		while (j < vec.size()-1){
			if (vec[j]>adad){
				cont++;
				ans.push_back(vec[j]);
				adad = vec[j];
			}
			//else if (vec[j + 1]<vec[j]&&vec[j+1]>adad){
			else if (vec[j]<adad&&vec[j]>i->first){
				int pak;
				for (int dd =  1; dd < ans.size(); dd++){
					if (vec[j] < ans[dd]){
						cont--;
						pak = dd;
					}
				}
				ans.erase(ans.begin() + pak, ans.end());
				//adad = vec[j];
				ans.push_back(vec[j]);
			}
			j++;
		}
		if (j == vec.size() - 1){
			if (vec[j] > vec[j - 1]){
				cont++;
				ans.push_back(vec[j]);
			}
		}
		result[cont] = ans;
		cout << "i->first   " << i->first << "cont   " << cont << endl;
		ans.clear();
		//i++;
		i--;
	}
	cout << "ghabel map\n";
	map<int, vector<int>>::iterator it;
	it = result.end();
	it--;
	cout << it->first << endl << "-" << endl;
	for (int d = 0; d < it->second.size(); d++){
		cout << it->second[d] << endl;
	}
}