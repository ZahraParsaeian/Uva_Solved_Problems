#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int s, b, l, r,result;
	while (cin >> s >> b&&s != 0 && b != 0){
		int *a = new int[s+1];
		while (b--){
			result = 0;
			cin >> l >> r;
			for (int i = l; i <= r; i++)
				a[i] = 1;
			for (int i = l - 1; i>0; i--){
				if (a[i] != 1){
					result = 1;
					cout << i << " ";
					break;
				}
			}
			if (!result)
				cout << "* ";
			result = 0;
			for (int i = r+1; i < s+1; i++){
				if (a[i] != 1){
					result = 1;
					cout <<i << endl;
					break;
				}
			}
			if (!result)
				cout << "*" << endl;
		}
		cout << "-\n";
	}
	return 0;
}