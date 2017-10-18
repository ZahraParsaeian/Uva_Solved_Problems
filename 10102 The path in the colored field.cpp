//#define Q10102
#ifdef Q10102

//AC

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include<math.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<pair<int, int>> vii;
int main() {
	//std::cout << "Hello, World!" << std::endl;
	int m, dist, minn;
	//vector<int> vec;
	vii se;

	while (cin >> m){
		se.clear();
		vvc vec(m, vc(m));
		set <int> ans;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < m; j++) {
				cin >> vec[i][j];
				if (vec[i][j] == '3')
					se.push_back(make_pair(i, j));
			}
		}
		for (int k = 0; k < m; ++k) {
			for (int i = 0; i < m; ++i) {
				if (vec[k][i] == '1'){
					minn = 1e9;
					for (int j = 0; j < se.size(); ++j) {
						minn = min(minn, abs(se[j].first - k) + abs(se[j].second - i));
					}
					ans.insert(minn);
				}
			}
		}
		set<int>::iterator it = ans.end(); it--;
		cout << *it << endl;


	}
	return 0;
}


#endif