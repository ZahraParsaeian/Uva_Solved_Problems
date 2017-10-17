//#define Q902
#ifdef Q902

//AC beautiful thinking

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
    
    int n; string a;
    while (cin >> n >> a){
        int k = -1; string ans;
        map <string , int > m;
        for (int i = 0; i < a.size() - n + 1; ++i) {
            string sub;
            int j = i;
            for (int k = 0; k < n; k++ , j++) sub += a[j];
            m[sub]++;
            if (m[sub] > k) k = m[sub] , ans = sub;
        }
        cout << ans << endl;
    }
    
    return 0;
}

#endif