#include<iostream>
#include<vector>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int tc,m,c,k,cost,cont,result;
	vector<int>remain1,remain2;
	cin >> tc;
	while (tc--){
		//cerr << "size    " << remain1.size() << endl;
		result = 0;
		cont = 1;
		cin >> m >> c;
		remain1.resize(m+10);
		remain2.resize(m+10);
		while (c--){
			cin >> k;
			while (k--){
				cin >> cost;
				if (cont == 1){
					if (m - cost >= 0)
						remain1[m - cost] = 1;
				}
				else if (cont > 1){
					for (int i = 0; i < remain1.size(); i++){
						if (remain1[i]){
							if (i - cost >= 0)
								remain2[i - cost] = 1;
						}
					}
				}
			}
			if (cont>1){
				remain1 = remain2;
				remain2.clear();
				remain2.resize(m+10);
			}
			cont++;
		}
		for (int i = 0; i < remain1.size(); i++){
			if (remain1[i]){
				result = 1;
				cout << m - i<<endl;
				break;
			}
		}
		if (!result)
			cout << "no solution\n";
		remain1.clear();
		remain2.clear();
	}
	return 0;
}