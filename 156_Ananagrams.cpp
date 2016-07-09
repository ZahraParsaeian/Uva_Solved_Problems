#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	map<char, int> first;   
	map<char, int> second;  
	string a;
	vector<string> vec;
	while (1){
		cin >> a;
		if (a == "#")
			break;
		vec.push_back(a);
	}
	int d,ee,cont,result,check,f=0,i=0,size2;
	char low;
	int size = vec.size();
	while (f < size){
		check = 0;
		d = i + 1;
		ee = i + 1;
		result = 0;
		for (int j = 0; j < vec[i].size(); j++){
			low = tolower(vec[i][j]);
			if (first.count(low)){
				first[low] = 2;
			}
			else
				first[low] = 1;
		}
		size2 = vec.size();
		while (d < size2){
			cont = 0;
			for (int e = 0; e < vec[ee].size(); e++){
				low = tolower(vec[ee][e]);
				if (second.count(low)){
					second[low] = 2;
				}
				else
					second[low] = 1;
			}
			if (first == second){
				vec.erase(vec.begin() + ee);
				result = 1;
				cont = 1;
			}
			if (cont == 0)
				ee++;
			second.clear();
			d++;
		}
		if (result == 1){
			vec.erase(vec.begin() + i);
			size--;
			check = 1;
		}
		if (check == 0){
			i++;
			size--;
		}
		f++;
		first.clear();
	}
	set<string>Set;
	for (int i = 0; i < vec.size(); i++){
		Set.emplace(vec[i]);
	}
	set<string>::iterator it;
	for (it = Set.begin(); it != Set.end(); it++){
		cout << *it << endl;
	}
	return 0;
}