#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	string a;
	int cont;
	map<char, int>sort;
	//vector<int>vec;
	while (cin >> a&&a != "#"){
		int size = a.size();
		if (size == 1){
			cout << "No Successor\n";
			continue;
		}
		cout << "size = " << size << endl;
		vector<int>vec(size);
		//vec.reserve(size);
		for (int i = size - 1; i >= 0; i--){
			//cont = size - i;
			cont = 0;
			for (int j = i - 1; j >= 0; j--){
				if (a[i] > a[j])
					break;
				cont++;
			}
			vec[i] = cont;
		}
			int min = 100, index = 0;
		    for (int i = 0; i <vec.size(); i++){
				if (vec[i] <= min  &&  i>index){
					min = vec[i];
					index = i;
				}
			}
			if (index - vec[index] - 1 < 0){
				cout << "No Successor\n";
				continue;
			}
			cout << "vec[index]= " << vec[index] << endl;
			cout << "vec[index] - index-1   =  " << index - vec[index] - 1 << endl;
			for (int i = 0; i < index - vec[index]-1; i++)
				cout << a[i];
			cout << a[index];
			for (int i = index - vec[index] - 1; i < size; i++){
				if (i != index){
					if (sort[a[i]] >= 1)
						sort[a[i]] ++;
					else
						sort[a[i]] = 1;
				}
			}
			map<char, int>::iterator it;
			for (it = sort.begin(); it != sort.end(); it++){
				for (int i = 0; i < it->second; i++)
					cout << it->first;
			}
		cout << endl;
		vec.clear();
		sort.clear();
	}
}