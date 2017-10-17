//#define Q10931
#ifdef Q10931

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
        string s=bitset<32>(n).to_string();
        int j = 0;
        for (j ; j < s.size(); j++)
            if (s[j] - '0')
                break;
        string a;
        for (int i = j; i < s.size(); ++i)
            a += s[i];
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
            ans += a[i] - '0';
        cout << "The parity of "<<a<<" is "<<ans<<" (mod 2).\n";
    }

    return 0;
}

#endif