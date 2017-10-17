//#define Q11553
#ifdef Q11553

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc,n,x;cin >> tc;
    while(tc--) {
        cin >> n;
        vector<vector<int>> game(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> game[i][j];
        }
        int arr[8]={0,1,2,3,4,5,6,7};
        int mn = 1000000;

        do {
            int sum1 = 0;
            for (int j = 0; j < n; j++) {
                sum1 += game[j][arr[j]];
            }
            mn = min(mn, sum1);
        } while (next_permutation(arr, arr + n));
        cout << mn << endl;
    }

    return 0;
}

#endif