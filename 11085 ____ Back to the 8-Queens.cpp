//#define Q11085
#ifdef Q11085

#include<iostream>
//#include<set>

using namespace std;

int qp[8], a, b, ch[8], cont, check, movee;
//set<int>max;

bool place(int r, int c){
	for (int i = 0; i < c; i++){
		if (qp[i] == r || (abs(qp[i] - r) == (abs(i - c))))
			return false;
	}
	return true;
}

void backtrack(int c){
	/*if (c == 7){
	if (qp[7] != ch[7])
	cont++;
	if (cont < movee)
	movee = cont;
	}*/
	for (int r = 0, cont = 0; r < 8; r++, cont = 0){
		if (place(r, c)){
			ch[c] = r;
			if (qp[c] != ch[c])
				cont++;
			if (cont < movee)
				movee = cont;
			backtrack(c + 1);
		}
	}
}
int main(){

	ios::sync_with_stdio(0);

	int  num, set = 1;
	while (cin >> num){
		movee = 9;
		num--;
		qp[num] = 0;
		cont = 0;
		for (int i = 1; i < 8; i++){
			cin >> num;
			num--;
			qp[num] = i;
		}
		for (int i = 0; i < 8; i++){
			a = qp[i];
			b = i;
			cont = 0;
			backtrack(0);
			if (cont < movee)
				movee = cont;
		}
		cout << "Case " << set << ": " << movee << endl;
		set++;
		memset(qp, 0, sizeof qp);
		memset(ch, 0, sizeof ch);
	}
}
#endif