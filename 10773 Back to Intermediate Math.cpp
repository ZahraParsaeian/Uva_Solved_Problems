//#define Q10773
#ifdef Q10773

//AC

#include <bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    int cont = 1;
    while (tc -- ){
        double d , u , v;
        cin >> d >> v >> u;
        cout << "Case "<<cont++<<": ";
        if (u - v <= 0 || v == 0) cout << "can't determine\n";
        else{
            double a = d / sqrt(u * u - v * v);
            double b = d / u;
            cout << fixed << setprecision(3) << abs(a - b)<< endl;
        }
    }

    return 0;
}

#endif