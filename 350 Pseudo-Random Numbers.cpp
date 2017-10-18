#define Q350
#ifdef Q350

#include<iostream>

using namespace std;

typedef pair<int, int>ii;

int z, i, m, l;

int f(int x){
	if (m != 0)
		return((z*x + i) % m);
}

int floydCycleFinding(int x){
	int tortoise = f(x), hare = f(f(x));
	while (hare != tortoise){
		tortoise = f(tortoise);
		hare = f(f(hare));
	}
	int lambda = 1;  hare = f(tortoise);
	while (tortoise != hare){
		hare = f(hare);
		lambda++;
	}
	return(lambda);
}

int main(){

	ios::sync_with_stdio(0);

	int cont = 1;
	while (cin >> z >> i >> m >> l){
		if (!z && !i && !m && !l){
			break;
		}
		cout << "Case " << cont++ << ": " << floydCycleFinding(l) << endl;
	}

	return 0;
}


#endif