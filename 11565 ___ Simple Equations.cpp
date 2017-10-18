//#define Q11565
#ifdef Q11565

//AC

#include<iostream>
#include<set>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int tc, a, b, c, result;
	cin >> tc;
	while (tc--){
		result = 1;
		cin >> a >> b >> c;
		for (int i = -22; i <= 22 && result; i++){
			if (i*i <= c){
				for (int j = -100; j <= 100; j++){
					if (i != j && (i*i + j*j) <= c){
						for (int k = -100; k <= 100 && result; k++){
							if (i != k &&  j != k && (i + j + k) == a && (i*j*k) == b && (i*i + j*j + k*k) == c&&result){
								cout << i << " " << j << " " << k << endl;
								result = 0;
							}
						}
					}
				}
			}
		}
		if (result)
			cout << "No solution.\n";
	}
	return 0;
}

#endif