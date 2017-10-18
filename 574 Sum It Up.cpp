//#define Q574
#ifdef Q574

#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int>vec,vis(12),ans(12),tmp;
int t,sum,n,sizeofnums;

void check(int i,int j,int cur){
		if (cur == t) {
			for (int a = 0; a <= i; a++)
				ans[a] = tmp[a];
			cout << ans[0];
			for (int k = 1; k <= i; k++) cout << "+" << ans[k];
			cout << endl;
		}
		//if (sum != t){
			for (int k = j + 1; k < n; k++){
					//if (vec[k] + cur <= t){
					if (vec[k] + cur <= t){
						tmp[i + 1] = vec[k];
						//check(i + 1, k, vec[k] + cur);
						check(i + 1, k, vec[k] + cur);
					}
				
			}
		//}
	
}

int main(){

	ios::sync_with_stdio(0);

	bool checking;
	while (cin >> t){
		checking = false;
		cin >> n;
		if (t == 0 && n == 0)
			break;
		if (n){
			cout << "Sums of " << t << ":" << endl;
			vec.clear();
			vec.resize(n);
			vis.clear();
			vis.resize(n);
			tmp.clear();
			tmp.resize(n);
			ans.clear();
			ans.resize(n);
			for (int i = 0; i < n; i++)
				cin >> vec[i];
			for (int i = 0; i < n; i++){
				sum = 0;
				ans.clear();
				ans.resize(n);
				sizeofnums = 0;
				tmp[0] = vec[i];
				check(0,i,vec[i]);
				/*if (sum == t){
					
					for (int j = 0; j <= sizeofnums; j++){
						checking = true;
						cout << ans[j];
						if (j != sizeofnums)
							cout << "+";
					}
					cout << endl;
				}*/
			}
			if (!checking)
				cout << "NONE\n";
		}
	}

	return 0;
}



#endif