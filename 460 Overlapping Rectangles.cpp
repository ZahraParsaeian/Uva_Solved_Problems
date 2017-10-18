//#define Q460
#ifdef Q460

//AC

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

	ios::sync_with_stdio(0);

	int tc;
	double xl1, xl2, xu1, xu2, yl1, yl2, yu1, yu2,ans1,ans2,ans3,ans4;
	cin >> tc;
	while (tc--){
		cin >> xl1 >> yl1 >> xu1 >> yu1;
		cin >> xl2 >> yl2 >> xu2 >> yu2;
		ans1 = max(xl1, xl2);
		ans2 = max(yl1, yl2);
		ans3 = min(xu1, xu2);
		ans4 = min(yu1, yu2);
		if (ans1 >= ans3 || ans2 >= ans4)
			cout << "No Overlap\n";
		else
			cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
		if (tc)
			cout << endl;
	}
	return 0;
}


#endif