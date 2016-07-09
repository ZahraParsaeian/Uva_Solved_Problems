#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace std;
int main(){

	ios::sync_with_stdio(false);

	set<char> Set = { 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y','1','8' };
	set<char> NextSet = { 'J', 'L', '2', 'S', 'E', '3', 'Z', '5' };
	map<char, char>Map;
	string a;
	int size, result;
	Map['A'] = 'A';
	Map['H'] = 'H';
	Map['I'] = 'I';
	Map['M'] = 'M';
	Map['O'] = 'O';
	Map['T'] = 'T';
	Map['U'] = 'U';
	Map['V'] = 'V';
	Map['W'] = 'W';
	Map['X'] = 'X';
	Map['Y'] = 'Y';
	Map['1'] = '1';
	Map['8'] = '8';
	Map['Z'] = '5';
	Map['5'] = 'Z';
	Map['E'] = '3';
	Map['3'] = 'E';
	Map['J'] = 'L';
	Map['L'] = 'J';
	Map['2'] = 'S';
	Map['S'] = '2';
	while (cin>>a){
		result = 1;
		size = a.size();
		if (size % 2 == 0)
			size = (size / 2) - 1;
		else
			size /= 2;
		for (int i = 0; i <= size; i++){
			if (Set.count(a[i])){
				if (Map[a[i]] != Map[a[a.size() - 1 - i]]){
					result = 0;
				}
			}
			else
				result = 0;
		}
		if (result == 1){
			cout << a << " -- is a mirrored palindrome.\n\n";
		}
		else{
			result = 1;
			for (int i = 0; i <= size; i++){
				if (i == size&&a.size()%2!=0){
					if (Set.count(a[i])==0){
						result = 0;
					}
				}
				else{
					if (Set.count(a[i]) || NextSet.count(a[i])){
						if (Map[a[i]] != a[a.size() - 1 - i]){
							result = 0;
						}
					}
					else
						result = 0;
				}
			}
			if (result == 1){
				cout << a << " -- is a mirrored string.\n\n";
			}
			else{
				result = 1;
				for (int f = 0; f <= size; f++){
					if (a[f] != a[a.size() - 1 - f]){
						result = 0;
					}
				}
				if (result == 1)
					cout << a << " -- is a regular palindrome.\n\n";
				else
					cout << a << " -- is not a palindrome.\n\n";
			}
		}
	}
	return 0;
}