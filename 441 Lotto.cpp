//#define Q441
#ifdef Q441

//AC

#include<iostream>
#include<set>

using namespace std;

int main(){

	ios::sync_with_stdio(0);

	int k,cont=0;
	set<int>s;
	while (cin >> k&&k!=0){
		if (cont != 0)
			cout << endl;
		int aa[49];
		for(int i=0;i<k;i++){
			cin >> aa[i];
		}
		for (int a = 0; a < k - 5; a++){
			for (int b = a + 1; b < k - 4; b++){
				for (int c = b + 1; c < k - 3; c++){
					for (int d = c + 1; d < k - 2; d++){
						for (int e = d + 1; e < k - 1; e++){
							for (int f = e + 1; f < k; f++){
								cout << aa[a] << " " << aa[b] << " " << aa[c] << " " << aa[d] << " " << aa[e] << " " << aa[f] << endl;
							}
						}
					}
				}
			}
		}
		cont++;
	}
	return 0;
}

#endif