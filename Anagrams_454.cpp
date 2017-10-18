#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	map<char, int> m;
	cout << atoi("\n")<<endl;
	char *mn = "horse cart";
	for (int i = 0; i < 10; i++){
		m[mn[i]] = i;
	}
	map<char, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++){
		if (it->first != ' ')
			cout << it->first << "       " << it->second << endl;
	}

}