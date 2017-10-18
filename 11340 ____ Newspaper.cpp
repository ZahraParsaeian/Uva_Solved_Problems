#include<iostream>
#include<map>
#include<string>
#include<sstream>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int tc,k,m,val,sum,cent,dollar;
	char a;
	map<char, int>match;
	string chert, charval,word;
	cin >> tc;
	while (tc--){
		cent = dollar = 0;
		cin >> k;
		getline(cin, chert);
		while (k--){
			getline(cin, charval);
			stringstream ss(charval);
			ss >> a;
			ss >> val;
			match[a] = val;
		}
		cin >> m;
		getline(cin, chert);
		while (m--){
			getline(cin, charval);
			stringstream str(charval);
			while (str >> word){
				for (int i = 0; i < word.size(); i++){
					if (match.count(word[i]))
						cent += match[word[i]];
					if (cent >= 100){
						dollar += cent / 100;
						cent = cent%100;
					}
				}
			}
		}
		cout << dollar << ".";
		if (cent < 10)
			cout << 0;
		cout << cent << "$\n";
		match.clear();
	}
	return 0;
}