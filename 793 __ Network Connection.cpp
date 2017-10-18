#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

vector<int> p;

void buildUF(int n){

	//p.resize(n + 1);
	p.assign(n + 1, 0);
	for (int i = 1; i <=n; i++)
		p[i]=i;
}

int FindSet(int i){
	return(p[i] == i ? i : p[i] = FindSet(p[i]));
}

bool IsSameSet(int i, int j){
	return FindSet(i) == FindSet(j);
}

void UnionSet(int i, int j){
	if (!IsSameSet(i, j)){
		int x = FindSet(i), y = FindSet(j);
		if (x >= y)
			p[x] = y;
		else{
			p[y] = x;
		}
	}
}

int main(){

	ios::sync_with_stdio(false);

	string a,chert;
	int tc,cnum,frs,sec,correct,wrong;
	cin >> tc;
	while (tc--){
		correct = 0;
		wrong = 0;
		cin >> cnum;
		buildUF(cnum);
		getline(cin, chert);
		while (getline(cin,a) &&a.length() != 0){
			stringstream ss;
			ss << a;
			char c;
			ss >> c;
			ss >> frs >> sec;
			if (c == 'c'){
				UnionSet(frs, sec);
			}
			else if (c == 'q'){
				if (IsSameSet(frs, sec))
					correct++;				
				else
					wrong++;
			}
		}
		cout << correct << "," << wrong << endl;
		if (tc != 0)
			cout << endl;
		p.clear();
	}
	return 0;
}