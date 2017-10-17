//#define Q11291
#ifdef Q11291

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

double val(string a){
    stack<string> s;
    stringstream str(a);
    string b;
    str >> b;
    if (b[0] == '(') {
        string f;
        f += b[0];
        s.push(f);
        s.push(b.substr(1, b.size() - 1));
    }
    else s.push(b);
    while(s.size() != 1 && s.top() != "("){
        while (str >> b && b[b.size() - 1] != ')')
            s.push(b);
        s.push(b.substr(0,b.size() - 1));
        if (s.top() != "("){
            string m = s.top();
            double aa = stod(m); s.pop();
            m = s.top();
            double bb = stod(m); s.pop();
            m = s.top();
            double p = stod(m); s.pop();
            s.pop();
            double ans = (aa + bb) * p + (bb - aa) * (1 - p);
            ostringstream strs;
            strs << ans;
            std::string t = strs.str();
            s.push(t);
        }
    }
    return stod(s.top());

}

int main(){

    ios::sync_with_stdio(0);

    string a;
    while (getline(cin , a) && a != "()"){
        cout << val(a) << endl;
    }

    return 0;
}

#endif