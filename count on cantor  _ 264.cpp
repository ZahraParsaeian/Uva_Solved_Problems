#include<iostream>
#include<math.h>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int num, result, numerator, denominator,raw,sum,start,dif;
	while (cin >> num){
		if (num >= 1){
			raw = sqrt(num * 8);
			raw++;
			raw /= 2;
			sum = raw + 1;
			start = ((raw*(raw - 1)) / 2)+1;
			dif = num - start;
			if (raw % 2 == 0){
				numerator = 1;
				denominator = raw;
				numerator += dif;
				denominator -= dif;
				if (dif==raw)
					denominator = 1;
			}
			else{
				numerator = raw;
				denominator = 1;
				numerator -= dif;
				denominator += dif;
				if (dif==raw)
					numerator = 1;
			}
			cout << "TERM " << num << " IS " << numerator << "/" << denominator << endl;
		}
	}
	return 0;
}