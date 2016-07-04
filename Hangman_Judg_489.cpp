#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	int n;
	int T, F;
	string word, ans;
	map<char, int> Map;
	map<char, int> checking;
	map<char, int> wrong;
	while (1){
		T = 0;
		F = 0;
		cin >> n;
		if (n == -1){
			break;
		}
		cin >> word;
		cin >> ans;
		for (int i = 0; i < word.size(); i++){
			if (Map.count(word[i])==0){
				Map[word[i]] = 1;
			}
		}
		for (int i = 0; i < ans.size(); i++){
			if (Map.count(ans[i])){
				if (T < Map.size()){
					if (checking.count(ans[i]) == 0){
						T++;
						checking[ans[i]] = 1;
						if (T == Map.size() && F < 7){
							cout << "Round " << n << endl << "You win." << endl;
						}
					}
				}
			}
			else{
				if (F < 7){
					if (wrong.count(ans[i]) == 0){
						F++;
						wrong[ans[i]] = 1;
						if (T < Map.size() && F == 7){
							cout << "Round " << n << endl << "You lose." << endl;
						}
					}
				}
			}
		}
		if (T < Map.size() && F < 7){
			cout << "Round " << n << endl << "You chickened out." << endl;
		}
		Map.clear();
		wrong.clear();
		checking.clear();
	}
	return 0;
}