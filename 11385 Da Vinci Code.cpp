#define Q11385
#ifdef Q11385

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

    vi fib(10000);
    map<ll ,ll> m;
    fib[0] = 1; m[1] = 1;
    fib[1] = 2; m[2] = 2;
    for (int i = 2; i < 10000; i++){
        int aa = fib[i - 1] + fib[i - 2];
        fib[i] = aa;
        m[aa] = i + 1;
    }
    int tc , n; cin >> tc;
    string a;
    while ( tc-- ){
        cin >> n;
        vi num(n);
        ll mx = -1;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
            mx = max(mx , m[num[i]]);
        }
        cin.ignore(100 , '\n');
        getline(cin , a);
        string vec;
        for (int i = 0; i < a.size(); ++i)
            if (isalpha(a[i]) && isupper(a[i]))
                vec += a[i];
        string vec2(mx , ' ');
        int j = 0;
        for (int i = 0; i < num.size(); ++i)
                vec2[m[num[i]] - 1] = vec[i];
        cout << vec2;
        cout << endl;
    }

    return 0;
}


#endif