//#define p10130
#ifdef p10130

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, int n){
	int i, w;
	vector<vector<int>> K;
	K.clear();
	K.resize(n + 1);
	for (int i = 0; i < n + 1; i++)
		K[i].resize(W + 1);

	for ( i = 0; i <= n; i++){
		for (w = 0; w <= W; w++){
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main(){
	vector<int> val;
	vector<int> wt;
	int tc; cin >> tc;
	int value;
	while (tc--){
		val.clear();
		wt.clear();
		value = 0;
		int obj; cin >> obj;
		while (obj--){
			int v, w; cin >> v >> w;
			val.push_back(v);
			wt.push_back(w);
		}
		int family; cin >> family;
		while (family--){
			int W; cin >> W;
			value += knapSack(W, wt, val, val.size());
		}
		cout << value << endl;
	}
	return 0;
}

#endif