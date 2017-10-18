#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<math.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int ch, sp, num, set = 0, result, diff;
	double sum;
	vector<int>spcmn1, spcmn2;
	while (cin >> ch >> sp){
		result = 0;
		sum = 0;
		diff = ch * 2 - sp;
		set++;
		for (int i = 0; i < sp; i++){
			cin >> num;
			sum += num;
			spcmn1.push_back(num);
		}
		sum /= ch;
		spcmn2 = spcmn1;
		sort(spcmn2.begin(), spcmn2.end());
		cout << "Set #" << set << endl;
		double imbalance=0,each;
		for (int i = 0; i < spcmn1.size(); i++){
			each = 0;
			for (int j = 0; j < spcmn2.size(); j++){
				if (spcmn2[j] == spcmn1[i]&& spcmn1[i]!=0){
					cout <<" "<<result<<": "<< spcmn1[i]<<" ";
					each += spcmn1[i];
					result++;
					if (j < sp - diff){
						each += spcmn2[sp - diff - 1 - j];
						cout << spcmn2[sp - diff - 1 - j];
						spcmn2[sp - diff - 1 - j] = -1;
					}
					imbalance += abs(each - sum);
					spcmn2[j]=-1;
					cout << endl;
					break;
				}
			}
		}
		while (result < ch){
			cout << " " << result << ":" << endl;
			imbalance += sum;
			result++;
		}
		cout << "IMBALANCE = " <<fixed<< setprecision(5) << imbalance << endl;
		spcmn1.clear();
		spcmn2.clear();
		cout << endl;
	}
	return 0;
}