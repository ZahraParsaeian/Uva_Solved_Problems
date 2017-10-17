//#define Q10137
#ifdef Q10137

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
#define inf 1e9
#define sup 1e-9

int main(){

    ios::sync_with_stdio(0);

    int n;
    while (cin >> n && n){
        double a;
        vd vec;
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            vec.push_back(a);
            sum += a;
        }
        sum /= n;
        double ans1 = 0 , ans2 = 0;
        for (int i = 0; i < vec.size(); ++i) {
            int d = (sum - vec[i]) * 100.0;
            if (d < 0)
                ans1 += d;
            else
                ans2 += d;
        }
        cout << "$" << fixed << setprecision(2) << (fabs(ans1) > ans2 ? fabs(ans1) : ans2) / 100 << endl;
    }

    return 0;
}

#endif