//#define Q10878
#ifdef Q10878

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

int BinToDec(string a){
    int ans = 0;
    int power = 1;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        if (a[i] != '0')
            ans += (a[i] - 48) * power;
        power *= 2;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

    string a;
    getline(cin , a);
    while (getline(cin , a)){
        if (a == "___________" ) break;
        char b; string ans = "";

        for (int i = 1; i < a.size()- 1; ++i) {
            if ( a[i] == ' ')
                ans += '0';
            else if ( a[i] == 'o')
                ans += '1';
        }
        int num = BinToDec(ans);
        if (num == 13) cout << endl;
        else cout << (char)num;
    }

    return 0;
}

#endif