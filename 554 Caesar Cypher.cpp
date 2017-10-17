//#define Q554
#ifdef Q554

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

    string a;
    set<string> s;
    vector<string> vec;
    while(getline(cin , a) && a != "#")
        vec.push_back(a);
    getline(cin ,a);
    string b = a;
    vector<pair<int , string>> ans;
    for (int j = 1; j < 27; ++j) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == ' ') b[i] = char('A' + j  - 1);
            else{
            b[i] = char((a[i] - 'A' + j) % 27 + 'A');
            if (b[i] == '[' ) b[i] = ' ';
            }
        }
        int sum = 0;
        for (int i = 0; i < vec.size(); ++i) {
            int a = b.find(vec[i]);
            if (a < b.size())
                sum++;
        }
        if (sum)
            ans.push_back(make_pair(sum ,b));
    }
    sort(ans.rbegin(), ans.rend());
    /*for (int i = 0; i < fin.size(); ++i) {
        if (fin[i] != ' ')
            cut += fin[i];
        else {
            //cut += ' ';
            if (cut.size() + chap.size() <= 60)
                chap += cut , chap += ' ';
            else{
                cout << chap << endl;
                chap.clear();
                chap += cut;
                chap += ' ';
            }
            cut.clear();
        }
    }
    cout << chap << endl;*/
    string fin = ans[0].second;
    vs final;
    string A = "";
    for (auto i : fin) {
        if (i != ' ')
            A += i;
        else{
            final.push_back(A);
            A = "";
        }
    }
    int strt = 0;
    for (auto i : final){
        if (strt + i.size() > 60 ) cout << endl , strt = 0;
        if (strt) cout << " " , strt++;
        cout << i ;
        strt += i.size();
    }
    cout << endl;

    return 0;
}

#endif