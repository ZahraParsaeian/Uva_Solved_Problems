//#define Q104
#ifdef Q104

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvd> vvvd;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef  stack<int> si;
#define inf 1e9
#define sup 1e-9

vvvd vec;
vvvi p;
int n;

void FW() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            p[i][j][0] = i;
    for (int step = 1; step < n; ++step)
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (vec[i][j][step] < vec[i][k][step - 1] * vec[k][j][0]) {
                        vec[i][j][step] = vec[i][k][step - 1] * vec[k][j][0];
                        p[i][j][step] = k;
                    }
}

void findans(){
    bool chk = false;
    for (int step = 1; step < n && !chk; ++step) {
        for (int i = 0; i < n; ++i) {
            if (vec[i][i][step] > 1.01){
                si s;
                s.push(p[i][i][step]);
                for (int j = step - 1; j >= 0 ; --j)
                    s.push(p[i][s.top()][j]);
                int tmp = s.top();
                while(!s.empty()){
                    cout << s.top() + 1 <<" ";
                    s.pop();
                }
                cout << tmp + 1;
                chk = true;
                break;
            }
        }
    }
    if(!chk) cout << "no arbitrage sequence exists";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(0);

    while (cin >> n) {
        vec.clear(); vec.resize(n , vvd(n , vd(n)));
        p.clear(); p.resize(n , vvi(n , vi(n)));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (i != j)
                    cin >> vec[i][j][0];
                else
                    vec[i][j][0] = 1;
            }
        FW();
        findans();
    }

    return 0;
}

#endif