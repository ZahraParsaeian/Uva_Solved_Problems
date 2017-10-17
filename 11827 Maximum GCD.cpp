//#define Q11827
#ifdef Q11827

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

int GCD(int a , int b){
    return (b == 0 ? a : GCD(b , a % b));
}

int main(){

    int tc;
    cin >> tc;
    cin.ignore();
    string a;
    while(tc--){
        getline(cin , a);
        stringstream str(a);
        int num;
        vi vec;
        while(str >> num)
            vec.push_back(num);
        int ans = -1;
        for (int i = 0; i < vec.size(); i++)
            for (int j = i + 1; j < vec.size(); j++)
                ans = max(ans , GCD(vec[i] , vec[j]));
        cout << ans << endl;
    }
}

#endif