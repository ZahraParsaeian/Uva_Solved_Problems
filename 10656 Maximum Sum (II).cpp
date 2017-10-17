//#define Q10656
#ifdef Q10656

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while ( cin >> n && n ){
        vi vec;
        int a;
        for ( int i = 0; i < n;i++){
            cin >> a;
            if ( a ) vec.push_back(a);
        }
        if ( vec.size()) {
            for (int i = 0; i < vec.size(); i++) {
                cout << vec[i];
                if (i != vec.size() - 1)
                    cout << " ";
            }
        }
        else cout << 0;
        cout << endl;
    }

    return 0;
}

#endif