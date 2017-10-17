//#define Q11389
#ifdef Q11389

//Please Be Careful :(((((((((((((((((((((((((((
//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int n,d,r;
    while(cin >> n >> d >> r && (n || d || r)){
        vi mor(n),aft(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i)
            cin >> mor[i];
        for( int i = 0; i < n; i++)
            cin >> aft[i];
        sort(mor.begin(),mor.end());   sort(aft.rbegin(),aft.rend());
        for ( int i = 0; i < n; i++)
            if ((aft[i] + mor[i]) > d)
                sum += aft[i] + mor[i] - d;
        cout << sum*r<<endl;
    }

    return 0;
}

#endif