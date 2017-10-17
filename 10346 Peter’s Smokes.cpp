//#define Q10346
#ifdef Q10346

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n , k;
    while (cin >> n >> k){
        int ans = n , q = n / k, r = n % k;
        ans += q;
        int sum = q + r;
        while(sum >= k){
            q = sum / k;
            r = sum % k;
            ans += q;
            sum = q + r;
        }
        cout << ans << endl;

    }

    return 0;
}

#endif