//#define Q1231
#ifdef Q1231

//AC


#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n , m , c;
    while (cin >> n >> m >> c && (n || m || c)){
        int ans = 0;
        if (c == 1){
            while (n >= 8 && m >= 8){
                ans += n / 2 - 3;
                ans += m / 2 - 3;
                ans --; m -- ; n -- ;
            }
        }
        else {
            while (n >= 8 && m >= 8){
                ans += (n + 1) / 2 - 4;
                ans += (m + 1) / 2 - 4;
                m -- ; n -- ;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

#endif