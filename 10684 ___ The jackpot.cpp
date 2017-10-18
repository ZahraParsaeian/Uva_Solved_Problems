//#define Q10684
#ifdef Q10684

//AC

#include<iostream>
#include<vector>

using namespace std;

int main(){

	ios::sync_with_stdio(0);

	int n,num,max,sum;
	vector<int>vec;
	while (cin >> n&&n){
		max = -1;
		sum = 0;
		for (int i = 0; i < n; i++){
			cin >> num;
			vec.push_back(num);
		}
		for (int i = 0; i < vec.size(); i++){
			sum += vec[i];
			if (sum >= 0){
				if (sum>max)
					max = sum;
			}
			else
				sum = 0;
		}
		if (max > 0)
			cout <<"The maximum winning streak is "<< max<<"." << endl;
		else
			cout << "Losing streak.\n";
		vec.clear();
	}
	return 0;
}

#endif