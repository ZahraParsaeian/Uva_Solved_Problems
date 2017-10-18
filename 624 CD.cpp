//#define Q624
#ifdef Q624

//AC

#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int n, sumofnums, size,sizeofnums;
vector<int>tmp(20), ans(20),num(20);

void solution(int i, int j, int cur){
	if (cur > sumofnums){
		sumofnums = cur;
		sizeofnums = i;
		for (int a = 0; a <= i; a++)
			ans[a] = tmp[a];
	}
	for (int k = j + 1; k < n; k++){
		if (num[k] + cur <= size){
			tmp[i + 1] = num[k];
			solution(i + 1, k, num[k] + cur);
		}
	}
}

int main(){

	ios::sync_with_stdio(0);

	while (cin >> size){
		sumofnums = 0;
		sizeofnums = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> num[i];
		}
		for (int i = 0; i < n; i++){
			tmp[0] = num[i];
			solution(0, i, num[i]);
		}
		for (int i = 0; i <=sizeofnums; i++){
			cout << ans[i] << " ";
		}
		cout << "sum:" << sumofnums << endl;
	}


	return 0;
}



#endif