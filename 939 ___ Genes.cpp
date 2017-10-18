#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int sstoi(string sec){
	if (sec == "dominant")
		return 3;
	else if (sec == "recessive")
		return 2;
	else if (sec == "non-existent")
		return 1;
}

string itoss(int num){
	if (num == 1)
		return ("non-existent");
	else if (num == 2)
		return("recessive");
	else if (num == 3)
		return("dominant");
}

int main(){

	ios::sync_with_stdio(false);

	int tc,sum;
	map<string, int> gn;
	map<string, vector<string>> notgn;
	cin >> tc;
	string frs,sec;
	while (tc--){
		cin >> frs >> sec;
		if (sec == "non-existent" || sec == "recessive" || sec == "dominant")
			gn[frs] = sstoi(sec);
		else{
			notgn[sec].push_back(frs);
		}
	}
	map<string, vector<string>>::iterator i;
	map<string, vector<string>>::iterator i2;
	i = notgn.begin();
	int size = notgn.size(), j = 0,cont=0;
	while (notgn.size()){
		if (j == size){
			size = notgn.size();
			i = notgn.begin();
			j = 0;
		}
		sum = 0;
		if (gn.count(i->second[0]) && gn.count(i->second[1])){
			sum += gn[i->second[0]];
			sum += gn[i->second[1]];
			if (sum != 5)
				sum /= 2;
			else
				sum = 3;
			gn[i->first] = sum;
			i2 = i++;
			notgn.erase(i2);
		}
		else
			i++;
		j++;
	}
	map<string, int>::iterator it;
	for (it = gn.begin(); it != gn.end(); it++){
		cout << it->first << " " << itoss(it->second) << endl;
	}
	return 0;
}