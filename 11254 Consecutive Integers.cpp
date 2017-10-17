//#define Q11254
#ifdef Q11254

//AC


#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n != -1){
        int sq = (int) sqrt(n * 2);
        int f, num;
        bool exist = false;
        for (double i = sq ; i >= 1; i--){
            int a = (((n * 2) / i ) - i + 1) / 2;
            //int b = (int )a;
            if (((i / 2) * (2 * a + i - 1)) == n) {
                num = i;
                f = a;
                exist = true;
                break;
            }
        }
        if (exist)  cout << n << " = " << f << " + ... + " << f + num - 1 << endl;
        else cout << n << " = " << n << " + ... + " << n << endl;

    }

    return 0;
}

#endif