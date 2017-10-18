//#define Q10192
#ifdef Q10192

//AC

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	ios::sync_with_stdio(0);

	string a, b;
	int m, n,cont=1;
	while (getline(cin,a) && a != "#"){
		//cin >> b;
		getline(cin, b);
		n = a.size();
		m = b.size();
		vector<vector<int>>vec(n+1, vector<int>(m+1,0));
		for (int i = 1; i <= n; i++)
			vec[i][0] =0;
		for (int j = 1; j <= m; j++)
			vec[0][j] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				vec[i][j] = vec[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 1 : 0);
				vec[i][j] = max(vec[i][j], vec[i - 1][j] );
				vec[i][j] = max(vec[i][j], vec[i][j - 1] );
			}
		}
		cout << "Case #"<<cont<<": you can visit at most "<<vec[n][m]<<" cities.\n";
		//cout << "Case #" << cont << ": you can visit at most " << vec[1][1] << " cities.\n";
		cont++;
		vec.clear();
	}
	return 0;
}

#endif