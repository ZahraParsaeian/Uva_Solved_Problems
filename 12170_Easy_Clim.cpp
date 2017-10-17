//#define Q12170
#ifdef Q12170

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int tc;cin >> tc;
    vector<int>stone,diff;
    int n,d,h;
    while(tc--) {
        stone.clear();
        diff.clear();
        cin >> n >> d;
        diff.resize(n);
        while (n--) {
            cin >> h;
            stone.push_back(h);
        }
        int count = 0;
        if (abs(stone[1] - stone[0]) > d) {
            if (stone[1] > stone[0]) {
                count += abs(stone[1] - stone[0] )+ d;
                stone[1] = stone[0] + d;
            } else {
                count += abs(abs(stone[0] - stone[1]) - d);
                stone[1] = stone[0] - d;
            }
        }
        //cerr << " count " <<count <<endl;
        int i = 1;
        for (i; i < stone.size() - 2; i++) {
            if (abs(stone[i] - stone[i + 1]) > d) {
                int sum = (stone[i] + stone[i + 1]) / 2;
                if (sum % 2 == 1) {
                    if (stone[i] < stone[i + 1]) {
                        count += abs(sum - 1 - stone[i]);
                        count += abs(sum + 1 - stone[i + 1]);
                        stone[i] = sum - 1;
                        stone[i + 1] = sum + 1;
                    } else {
                        count += abs(sum - 1 - stone[i + 1]);
                        count += abs(sum + 1 - stone[i]);
                        stone[i] = sum + 1;
                        stone[i + 1] = sum - 1;
                    }
                    //cerr << " count fard" << count <<endl;
                } else {
                    if (stone[i] < stone[i + 1]) {
                        count += abs(sum - stone[i]);
                        count += abs(sum + 2 - stone[i + 1]);
                        stone[i] = sum;
                        stone[i + 1] = sum + 2;
                    } else {
                        count += abs(sum - stone[i + 1]);
                        count += abs(sum + 2 - stone[i]);
                        stone[i] = sum + 2;
                        stone[i + 1] = sum;
                    }
                    //cerr << "count zoj " << count << endl;
                }
            }

        }
        if (abs(stone[i] - stone[stone.size() - 1]) > d) {
            if (stone[i] > stone[stone.size() - 1]) {
                count += abs(stone[i] - stone[stone.size() - 1]) + d;
                stone[i] = (stone[stone.size() - 1] + d);
            } else {
                count += abs(abs(stone[stone.size() - 1] - stone[i] )- d);
                stone[i] = (stone[stone.size() - 1] - d);
            }
        }
        bool check = true;
        for (int j = 0; j < stone.size() - 1; j++) {
            if (abs(stone[j] - stone[j + 1]) > d)
                check = false;
        }
        if (check)
            cout << count << endl;
        else
            cout << "impossible" << endl;
    }

    return 0;
}



#endif