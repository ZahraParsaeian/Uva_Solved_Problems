//#define Q821
#ifdef Q821


#include<iostream>
#include<set>
#include<algorithm>
#include<iomanip>

//AC

using namespace std;

int rec[101][101];
#define INF (int)1e9

int main(){

	ios::sync_with_stdio(0);

	int a, b, c, d,cont=1;
	set<int>s;
	while (cin >> a >> b){
		for (int i = 0; i < 101; i++){
			for (int j = 0; j < 101; j++)
				rec[i][j] = INF;			
		}
		if (!a&&!b)
			break;
		rec[a][b] = 1;
		s.insert(a);       s.insert(b);
		while (cin >> a >> b){
			if (!a && !b)
				break;
			rec[a][b] = 1;
			s.insert(a);     s.insert(b);
		}
		for (int k = 0; k < 101; k++){
			for (int i = 0; i < 101; i++){
				for (int j = 0; j < 101; j++){
					rec[i][j] = min(rec[i][j], rec[i][k] + rec[k][j]);
				}
			}
		}
		//double jj = (1 << s.size()) - s.size();
		double sum = 0,jj=0;
		
	/*	set<int>::iterator i,j;
		for (i = s.begin(); i != s.end(); i++){
			for (j = s.begin(); j != s.end(); j++)
				sum += rec[*i][*j];
		}*/
		for (int i = 0; i < 101; i++){
			for (int j = 0; j < 101; j++){
				if (rec[i][j] != INF&&i!=j)
					sum += rec[i][j], jj++;
			}
		}
		cout << "Case "<<cont<<": average length between pages = "
		     << fixed << setprecision(3) << sum /jj <<" clicks"<< endl;
		s.clear();
		cont++;
	}

	return 0;
}

#endif