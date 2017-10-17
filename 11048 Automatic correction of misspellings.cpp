//#define Q11048
#ifdef Q11048

//AC
//check why ur code is wrong

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

bool same(string a , string b) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == b[i]) ans++;
    if (ans == a.size() - 1) return true;
    int i = 0;
    for (; i < a.size(); i++)
        if (a[i] != b[i])
            break;
    if (a[i] == b[i + 1] && b[i] == a[i + 1]){
        i += 2;
        for (; i < a.size(); i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
    return false;
}

bool dif(string a, string b){
    /*if(b.size() < a.size()) swap(a , b);
    if (a[0] == b[0] && a[a.size() - 1] != b[b.size() -1]){
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    else if (a[0] != b[0] && a[a.size() - 1] == b[b.size() - 1]){
        int i = int(a.size()) - 1;
        int j = int(b.size()) - 1;
        for (int k = 0; k < a.size(); k++){
            if(a[i] != b[j])
                return false;
            i--;
            j--;
        }
        return true;
    }
    else if (a[0] == b[0] && a[a.size() - 1] == b[b.size() - 1]){
        int j = 0 , sum = 0;
        for (int i = 0; i < a.size(); ++i) {
            if(a[i] != b[j]){
                if (sum == 0){
                    j ++;
                    sum = 1;
                }
                else return false;
            }
            j++;
        }
        return true;
    }*/
    if(a.size() < b.size()) swap(a, b);
    if(a.size() - b.size() != 1) return false;
    int n = 0;
    for(int i = 0; i < a.size(); i++)
        if(a[i] != b[i - n]) n++;
    return n == 1;
}

int main() {

    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vs dic(n);
    for (int i = 0; i < n; ++i)
        cin >> dic[i];
    int q;
    cin >> q;
    string a;
    for (int i = 0; i < q; ++i) {
        cin >> a;
        bool check = false;
        for (auto w : dic) {
            if (a == w) {
                cout << a << " is correct\n";
                check = true;
                break;
            }
        }
        if (!check) {
            for (auto e : dic) {

                if (a.size() == e.size()) {
                    if (same(a, e)) {
                        cout << a << " is a misspelling of " << e << endl;
                        check = true;
                        break;
                    }
                }
                else if (abs(int(a.size()) - int(e.size())) == 1) {
                    if (dif(a, e)) {
                        cout << a << " is a misspelling of " << e << endl;
                        check = true;
                        break;
                    }
                }
            }
        }
        if (!check) cout << a << " is unknown\n";

    }

    return 0;
}

#endif