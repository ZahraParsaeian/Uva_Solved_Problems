#define Q100645
#ifdef Q100645

#include<iostream>
#include<vector>
#include<map>
#include<utility>

using namespace std;

int main(){

	ios::sync_with_stdio(0);

	int n, m, much,min,b,cont;
	vector<int>remain1,remain2;
	//int remain1[10000], remain2[10000];
	map<int, int>max;
	while (cin >> n >> m >> much){
		b = much;
		cont = 1;
		if (n < m)
			min = n;
		else
			min = m;
		remain1.resize(much);
		remain2.resize(much);
		//memset(remain1, 0, sizeof remain1);
		//memset(remain2, 0, sizeof remain2);
		if (much-m>=0)
			remain1[much - m] = 1;
		if (much-n>=0)
			remain1[much - n] = 1;
		while (b>=min){
			cont++;
			for (int i = 0; i < much; i++){
				if (remain1[i] == 1){
					if (i - m >= 0)
						remain2[i - m] = 1;
					if (i-n>=0)
						remain2[i - n] = 1;
					if ((i - n) == 0)
						max[cont] = 1;
					if (i - m == 0)
						max[cont] = 1;
					b = i - min;
				}
			}
			//swap(remain1, remain2);
			//memset(remain2, 0, sizeof remain2);
			remain1 = remain2;
			remain2.clear();
			remain2.resize(much);
		}
		map<int, int>::iterator it;
		for (int i = 0; i < much; i++){
			if (remain1[i] == 1){
				if (i == 0)
					cout << cont << endl;
				else{
					if (max.size() != 0){
						it = max.end();
						it--;
						cout << it->first << endl;
					}
					else
						cout << cont << " " << i << endl;
						
				}
				break;
			}
		}
		max.clear();
		remain1.clear();
		remain2.clear();
	}
	return 0;
}

#endif 