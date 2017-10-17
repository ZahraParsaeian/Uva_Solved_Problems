//#define Q10940
#ifdef Q10940

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n){
        if (n != 1) {
            int a = (int )log2 (n);
            int b = a - 1;
            a = n - pow (2 , a );
            if (a == 0)
                a = pow (2 , b);
            cout << a * 2 << endl;
        }
        else cout << 1 << endl;
    }

    return 0;
}

#endif