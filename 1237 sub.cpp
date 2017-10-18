//#define Q1237
#ifdef Q1237

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	//std::cout << "Hello, World!" << std::endl;
	ios::sync_with_stdio(0);
	int tc, db, que;
	string name, ans;
	int high, low, price, count;
	map<string, pair<int, int> > car;
	cin >> tc;

	while (tc--) {
		car.clear();
		count = 0;
		cin >> db;
		while (db--) {
			cin >> name >> low >> high;
			car[name] = make_pair(low, high);
		}
		cin >> que;
		map<string, pair<int, int> >::iterator it;
		while (que--) {
			cin >> price;
			count = 0;
			for (it = car.begin(); it != car.end(); it++) {
				if (price >= (it->second.first) && price <= (it->second.second)) {
					count++;
					if (count == 2)
						break;
					ans = it->first;
				}
			}
			if (count == 0 || count == 2)
				cout << "UNDETERMINED" << endl;
			else if (count==1)
				cout << ans << endl;
			
		}
		if (tc)
				cout << endl;

		
	}
	return 0;
}

#endif