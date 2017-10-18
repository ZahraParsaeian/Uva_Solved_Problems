//#define Q1260
#ifdef Q1260

//AC
#include<iostream>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int tc, n, i,sum;
	cin >> tc;
	while (tc--){
		int a[1000], b[1000] = { 0 };
		sum = 0;
		cin >> n;
		i = 0;
		while (i < n){
			cin >> a[i];
			i++;
		}
		for (int j = 0; j < n; j++){
			for (int e = j-1; e>=0; e--){
				if (a[e] < a[j])
					b[j]++;
				else if (a[e] == a[j]){
					b[j] += b[e];
					b[j]++;
					break;
				}
			}
			sum += b[j];
		}
		cout << sum << endl;
	}
	return 0;
}

#endif