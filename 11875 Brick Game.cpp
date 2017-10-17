//#define Q11875
#ifdef Q11875

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc , cont = 1; cin >> tc;
    while (tc -- ){
        int n;
        cin >> n;
        vector<int > vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        n = (n - 1) / 2;
        cout << "Case "<<cont++<<": "<<vec[n]<<endl;
    }
}

#endif