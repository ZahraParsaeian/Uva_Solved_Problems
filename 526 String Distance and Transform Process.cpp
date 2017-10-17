//#define Q526
#ifdef Q526

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

vvii vec;
string a , b;
int n , m;

void score(){
    vec[0][0].first = -1, vec[0][0].second = 0;
    for (int i = 1; i <= n; i++) vec[i][0].second = i * 1 , vec[i][0].first = 2;
    for (int j = 1; j <= m; j++) vec[0][j].second = j * 1, vec[0][j].first = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int &x = vec[i][j].second , &y = vec[i][j].first;
            x = vec[i - 1][j - 1].second + (a[i - 1] == b[j - 1] ? 0 : 1) , y = 0;
            if (x > vec[i - 1][j].second + 1 )
                y = 2 , x = vec[i - 1][j].second + 1;
            if (x > vec[i][j - 1].second + 1) {
                y = 1 , x = vec[i][j - 1].second + 1;
            }
        }
    }
}

void prnt(){
    vector<pair<string,pair<int,char>>> ans;
    int i = n , j = m;
    vii move = {{-1 , -1} , {0 , -1} , {-1 , 0}};
    while(vec[i][j].first != -1) {
        int mv = vec[i][j].first;
        if (mv == 0) {
            if (a[i- 1] != b[j - 1])
                ans.push_back(make_pair("Replace" ,make_pair( i ,b[j - 1])));
        }
        else if (mv == 2)
            ans.push_back(make_pair("Delete" , make_pair(i , ' '))) ;
        else if (mv == 1)
            ans.push_back(make_pair("Insert" , make_pair(j ,  b[j - 1]))) ;
        i += move[mv].first; j += move[mv].second;
    }
    cout << ans.size() << endl;
    int cont = 1;
    int pos = 0;
    for (int l = int(ans.size()) - 1 ; l >= 0; l--){
        if (ans[l].first == "Replace")
            cout << cont++ << " " << ans[l].first << " " << ans[l].second.first + pos << "," << ans[l].second.second << endl;
        if (ans[l].first == "Delete")
            cout << cont++ << " " << ans[l].first << " " << ans[l].second.first + pos << endl ,pos--;
        else if (ans[l].first == "Insert")
            cout << cont++ << " " << ans[l].first << " " << ans[l].second.first << "," << ans[l].second.second << endl, pos++;
    }
}

int main() {

    ios::sync_with_stdio(0);

    int cont = 0;
    while (getline(cin , a) && getline(cin , b)) {
        if (cont++) cout << endl;
        n = int(a.size()), m = int(b.size());
        vec.clear();
        vec.resize(n + 10, vii(m + 10, make_pair(inf, 0)));
        score();
        prnt();
    }

    return 0;
}

#endif