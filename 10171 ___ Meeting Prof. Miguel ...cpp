//#define Q10171
#ifdef Q10171

//AC

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define INF (int)1e9
int old[26][26], yng[26][26],o,y;

int main(){

	ios::sync_with_stdio(0);

	int n,energy;
	char a, b, c, d;
	while (cin >> n && n){
		for (int i = 0; i < 26; i++){
			for (int j = 0; j < 26; j++){
				if (i != j)    old[i][j] = yng[i][j] = INF;
				else        old[i][j] = yng[i][j] = 0;
			}
		}
		while (n--){
			cin >> a >> b >> c >> d >> energy;
			int f = c - 'A', s = d - 'A';
			if (f != s){
				if (a == 'Y'){
					yng[f][s] = energy;
					if (b == 'B')
						yng[s][f] = energy;
				}
				else{
					old[f][s] = energy;
					if (b == 'B')
						old[s][f] = energy;
				}
			}
		}
		for (int k = 0; k < 26; k++){
			for (int i = 0; i < 26; i++){
				for (int j = 0; j < 26; j++){
					old[i][j] = min(old[i][j], old[i][k] + old[k][j]);
					yng[i][j] = min(yng[i][j], yng[i][k] + yng[k][j]);
				}
			}
		}
		cin >> a >> b;     y = a - 'A';    o = b - 'A';
		int ans = INF;
		for (int i = 0; i < 26; i++){
			if (old[o][i] != INF&&yng[y][i]!=INF)
				ans = min(ans, old[o][i] + yng[y][i]);
		}
		vector<char>dis;
		for (int i = 0; i < 26; i++){
			if (ans == old[o][i] + yng[y][i])
				dis.push_back(i + 'A');
		}
		if (ans == INF) cout << "You will never meet.\n";
		else {
			cout << ans;
			for (int i = 0; i < dis.size(); i++)
				cout << " " << dis[i];
			cout << endl;
		}
	}
	return 0;
}

#endif