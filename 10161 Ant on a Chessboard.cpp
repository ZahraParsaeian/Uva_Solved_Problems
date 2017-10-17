//#define Q10161
#ifdef Q10161

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n){
        int a = (int)floor(sqrt(n));
        int b = (int)ceil(sqrt(n));
        int x , y;
        if (pow (a , 2) == n){
            if (n % 2 == 0)
                x = a , y = 1;
            else
                x = 1 , y = a;
        }
        else {
            if (a % 2 == 0) {
                x = a + 1;
                if (n - pow(a, 2) <= b)
                    y = n - pow(a, 2);
                else
                    x = pow(b, 2) - n + 1 , y = b;
            } else {
                y = a + 1;
                if (n - pow(a, 2) <= b)
                    x = n - pow(a, 2);
                else
                    y = pow(b, 2) - n + 1 , x = a + 1;
            }
        }
        cout << x << " " << y << endl;
    }

    return 0;
}

#endif