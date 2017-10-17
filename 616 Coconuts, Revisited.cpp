//#define Q616
#ifdef Q616

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n >= 0){
        if (n != 3) {
            int sq = (int) sqrt(n - 1);
            bool ok = false;
            int ans;
            for (int i = sq; i >= 2; --i) {
                bool happen = true;
                int num = n;
                for (int j = 0; j < i; ++j) {
                    if ((num - 1) % i != 0) {
                        happen = false;
                        break;
                    }
                    num -= (num / i) + 1;
                }
                if (happen) {
                    if (num == 0 || num % i == 0) {
                        ok = true;
                        ans = i;
                        break;
                    }
                }
            }
            if (ok)
                cout << n << " coconuts, " << ans << " people and 1 monkey\n";
            else
                cout << n << " coconuts, no solution\n";
        }
        else cout <<"3 coconuts, 2 people and 1 monkey\n";
    }

    return 0;
}

#endif