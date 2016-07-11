#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int a, b, c, d,night,hight,fatigue,cont;
	float sum,day,ff;
	vector<list<int>>vec;
	list<int> lis;
	while (1){
		cin >> a >> b >> c >> d;
		if (a == 0)
			break;
		//if (a >= 1 && a <= 100 && b >= 1 && b <= 100 && c >= 1 && c <= 100 && d >= 1 && d <= 100){
			lis.insert(lis.end(), a);
			lis.insert(lis.end(), b);
			lis.insert(lis.end(), c);
			lis.insert(lis.end(), d);
			vec.push_back(lis);
		//}
		lis.clear();
	}
	for (int i = 0; i < vec.size(); i++){
		sum = 0;
		cont = 1;
		list<int>::iterator it;
		it = vec[i].begin();
		hight = *it;
		it++;
		day = *it;
		it++;
		night = *it;
		it++;
		fatigue = *it;
		ff = day*(float)fatigue / 100;
		sum += day;
		if (sum > hight){
			cout << "success on day " << cont << endl;
			continue;
		}
		sum -= night;
		if (sum < 0){
			cout << "failure on day " << cont << endl;
			continue;
		}
		while (sum >= 0 && sum <= hight){
			cont++;
			if (day!=0)
				day -= ff;
			sum += day;
			if (sum>hight)
				break;
			sum -= night;
		}
		if (sum > hight)
			cout << "success on day " << cont << endl;
		else if (sum < 0)
			cout << "failure on day " << cont << endl;
	}
	return 0;
}