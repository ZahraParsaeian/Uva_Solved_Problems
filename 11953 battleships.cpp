//#define Q11953
#ifdef Q11953

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvc vec;  vvi vis;

int d1[] = {-1 , 1 , 0 , 0} , d2[] = {0 , 0 , -1 , 1};
int n;

void check(int a , int b) {
    if (a < 0 || a  >= n || b  < 0 || b >= n) return;
    vec[a][b] = 'z';
    for (int i = 0; i < 4; i++) {
        //if (a + d1[i]< 0 || a + d1[i] >= n || b + d2[i] < 0 || b + d2[i] >= n) continue ;
        if (a + d1[i] >= 0 && a + d1[i] < n && b + d2[i] >= 0 && b + d2[i] < n)
        if ( vec[a + d1[i]][b + d2[i]] == 'x' || vec[a + d1[i]][b + d2[i]] == '@')  check(a + d1[i] , b + d2[i]);
    }
}

int main(){

    ios::sync_with_stdio(0);

    int tc, cont = 1;  cin >> tc;
    while ( tc-- ) {
        cin >> n;
        vec.clear();
        vec.resize(n + 2, vc(n + 2));
        vis.clear();
        vis.resize(n + 2, vi(n + 2, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> vec[i][j];
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (vec[i][j] == 'x') {
                    ans++;
                    check(i, j);
                }

        cout << "Case " << cont++ << ": " << ans << endl;
    }

    return 0;
}

#endif