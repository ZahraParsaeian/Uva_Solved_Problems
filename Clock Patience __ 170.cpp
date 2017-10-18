#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int cont;
	string in;
	int i , j, t;
	while (cin >> in&&in != "#") {
		vector<vector<string>>input(13, vector<string>(4));
		i = 12;
		j = 3;
		t = 1;
		cont = 0;
		input[i][j] = in;
		i--;
		while (t < 52){
			cin >> in;
			input[i][j] = in;
			if (i == 0) {
				i = 13; j--;
			}
			if (j == -1)
				j = 3;
			i--;
			t++;
		}
		char b;
		char a = input[12][input[12].size() - 1][0];
		string ans;
		ans = input[12][input[12].size() - 1];
		input[12].pop_back();
		cont++;
		while (1){
			if (a - 48 == 2 || a - 48 == 3 || a - 48 == 3 || a - 48 == 4 || a - 48 == 5
				|| a - 48 == 6 || a - 48 == 7 || a - 48 == 8 || a - 48 == 9) {
				b = a;
				if (input[b - 48 - 1].size() == 0)
					break;
				ans = input[(a - 48) - 1][input[(a - 48) - 1].size() - 1];
				a = input[(a - 48) - 1][input[(a - 48) - 1].size() - 1][0];
				input[(b - 48) - 1].pop_back();
				cont++;
			}
			else if (a == 'A') {
				if (input[0].size() == 0)
					break;
				a = input[0][input[0].size() - 1][0];
				ans = input[0][input[0].size() - 1];
				input[0].pop_back();
				cont++;
			}
			else if (a == 'K') {
				if (input[12].size() == 0)
					break;
				a = input[12][input[12].size() - 1][0];
				ans = input[12][input[12].size() - 1];
				input[12].pop_back();
				cont++;
			}
			else if (a == 'Q') {
				if (input[11].size() == 0)
					break;
				a = input[11][input[11].size() - 1][0];
				ans = input[11][input[11].size() - 1];
				input[11].pop_back();
				cont++;
			}
			else if (a == 'T'){
				if (input[9].size() == 0)
					break;
				a = input[9][input[9].size() - 1][0];
				ans = input[9][input[9].size() - 1];
				input[9].pop_back();
				cont++;
			}
			else if (a == 'J'){
				if (input[10].size() == 0)
					break;
				a = input[10][input[10].size() - 1][0];
				ans = input[10][input[10].size() - 1];
				input[10].pop_back();
				cont++;
			}
		}
		if (cont < 10)
			cout << 0 << cont << "," << ans << endl;
		else
			cout << cont << "," << ans << endl;
		input.clear();
	}
	return 0;
}