//#define Q10916
#ifdef Q10916

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n){
        double a = (n - 1960) / 10 + 2;
        double b = pow (2 , a) * log10(2) , sum = 0;
        cout << "b  " << b << endl;
        int i = 1;
        while(true){
            sum += log10(i);
            cout << "i " << i << "  sum  "<< sum << endl;
            if (sum > b)
                break;
            i++;
        }
        cout << i - 1 << endl;
    }

    return 0;
}

#endif