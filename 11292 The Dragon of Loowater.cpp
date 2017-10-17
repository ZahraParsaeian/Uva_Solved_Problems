//#define Q11292
#ifdef Q11292

// One way for solving GREEDY problems is to sort them
//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {

    ios::sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m && (n || m)) {
        vi hd(n) , kgt(m);
        for ( int i = 0; i < n; i++)  cin >> hd[i];
        for ( int i = 0; i < m; i++)  cin >> kgt[i];
        sort(hd.begin() , hd.end());  sort(kgt.begin() , kgt.end());
        int i = 0, j = 0, ans = 0;
        while( i < n && j < m ){
            while ( hd[i] > kgt[j] && j < m ) j++;
            if ( j == m ) break;
            ans += kgt[j];
            i++ , j++;
        }
        if ( i == n ) cout << ans << endl;
        else cout << "Loowater is doomed!\n";
    }
}
#endif