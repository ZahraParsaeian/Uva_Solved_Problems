#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	int num, e, sum, jam;
	cin >> n;
	string a;
	vector<string> answer;
	for (int i = 0; i < n; i++){
		vector<string>vec1;
		vector<string>vec2;
		sum = 0;
		jam = 0;
		for (int j = 0; j <26; j++){
			cin >> a;
			vec1.push_back(a);
		}
		for (int j = 0; j <26; j++){
			cin >> a;
			vec2.push_back(a);
		}
		for (int w = 0; w < 3; w++){
			e = vec1[jam].at(0) - 48;
			if (e == 2 || e == 3 || e == 4 || e == 5 || e == 6 || e == 7 || e == 8 || e == 9){
				sum += e;
				jam+= (11 - e);					
			}
			else{
				sum += 10;
				jam += 1;
			}
		}
		vec1.erase(vec1.end() - jam, vec1.end());
		if (sum <vec1.size()){
			cout << "Case " << i + 1 << ": " << vec1[sum-1] << endl;
		}
		else{
			sum -= vec1.size();
			cout << "Case " << i + 1 << ": " << vec2[sum-1] << endl;

		}
		vec1.clear();
		vec2.clear();
	}
}