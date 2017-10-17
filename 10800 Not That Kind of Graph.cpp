//#define Q10800
#ifdef Q10800

//AC

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef  stack<int> si;
typedef queue<int> qi;
typedef map<int,int> mii;
typedef queue<ii> qii;
typedef pair<int , double> id;
typedef vector<id> vid;
typedef vector<vid> vvid;
typedef vector<ll> vll;
typedef vector<string> vs;
#define inf 1e9
#define sup 1e-9

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    int cont = 1;
    while (tc--){
        string a;
        cin >> a;
        int up = 2 , mx = 2 , mn = inf , up2 = 2;
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] == 'R' && a[i - 1] == 'R') up++;
            else if (a[i] == 'C' && a[i - 1] == 'R') up++;
            else if (a[i] == 'F' && a[i - 1] != 'R') up--;
            if (up < 2)
                mn = min(mn , up);
        }
        if (mn != inf && mn != 2) up = 2 - mn + 2 , up2 = up;
        else up = 2 , up2 = 2;
        for (int i = 1; i < a.size(); ++i) {
            if (a[i] == 'R' && a[i - 1] == 'R') up++;
            else if (a[i] == 'C' && a[i - 1] == 'R') up++;
            else if (a[i] == 'F' && a[i - 1] != 'R') up--;
            mx = max(mx , up);
        }
        up = max(up2 , mx);
        vvc vec(up + 3 , vc(a.size() + 6 , ' '));
        for (int i = 0; i < up - 1; ++i)
            vec[i][0] = '|';
        vec[up - 1][0] = '+';
        for (int j = 1; j < a.size() + 3; ++j)
            vec[up - 1][j] = '-';
        int i = up - 2, j = 2;
        if (mn != 2 && mn != inf) i -= (2 - mn);
        char pre;
        if (a[0] == 'R') vec[i][j] =  '/' , pre = 'R';
        else if (a[0] == 'F') vec[i][j] = '\\' , pre = 'F';
        else if (a[0] == 'C') vec[i][j] = '_' , pre = 'C';
        j++;
        for (int k = 1; k < a.size(); k++){
            if (a[k] == 'R' ) {
                if (pre == 'R') i--;
                vec[i][j] = '/';
                pre = 'R';
            }
            else if (a[k] == 'F') {
                if (pre != 'R')
                    i++;
                vec[i][j] = '\\';
                pre = 'F';
            }
            else if (a[k] == 'C') {
                if (pre == 'R')
                    i--;
                vec[i][j] = '_';
                pre = 'C';
            }
            j++;
        }
        cout << "Case #" << cont++ << ":\n";
        for (int i = 0; i < up ; ++i) {
            int k = a.size() + 2;
            for (; k >= 0; k--)
                if (vec[i][k] != ' ')
                    break;
            for (int j = 0; j <= k; ++j) {
                cout << vec[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

#endif