#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

	int n,num;
	cin >> n;    cerr << n << endl;
	vector<vector<int>>vec(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> vec[i][j];
			if (i>0)
				vec[i][j] += vec[i - 1][j];
			if (j>0)
				vec[i][j] += vec[i][j - 1];
			if (i > 0 && j > 0)
				vec[i][j] -= vec[i - 1][j - 1];
		}
	}
	int max = -127 * 100 * 100,sr;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = i; k < n; k++){
				for (int l = j; l < n; l++){
					sr = vec[k][l];
					if (i>0)
						sr -= vec[i - 1][l];
					if (j>0)
						sr -= vec[k][j - 1];
					if (i>0 && j>0)
						sr += vec[i - 1][j - 1];
					if (max < sr)
						max = sr;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}