//#define Q11371
#ifdef Q11371

//AC

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
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
typedef unsigned long long ull;
#define inf 1000000000
#define sup 1e-9f

ll vectoll(vi vec){
    int size = vec.size();
    ll ans = 0;
    ll p = 1;
    for (int i = size - 1; i >= 0; i--){
        ans += vec[i] * p;
        p *= 10;
    }
    return ans;
}

vi lltovec(ll a){
    vi vec;
    while(a){
        vec.push_back(a % 10);
        a /= 10;
    }
    return vec;
}

int main(){

    ios::sync_with_stdio(0);

    ll n;
    while (cin >> n){
        vi vec = lltovec(n);
        vi vec1 = vec;
        sort(vec1.begin(), vec1.end());
        sort(vec.rbegin(), vec.rend());
        ll a = vectoll(vec);
        ll b = vectoll(vec1);
        vi check = lltovec(b);
        while(check.size() != vec.size()){
            next_permutation(vec1.begin(), vec1.end());
            b = vectoll(vec1);
            check = lltovec(b);
        }
        ll diff1 = abs (a - n) , diff2 = abs(b - n);
        ll diff = a - b;
        /*if (diff1 > diff2)
            cout << a << " - " << n << " = " << diff1 << " = " << "9 * " << diff1/9 << endl;
        else
            cout << n << " - " << b << " = " << diff2 << " = " << "9 * " << diff2/9 << endl;*/
        cout <<  a << " - " << b << " = " << diff << " = " << "9 * " << diff/9 << endl;
    }

    return 0;
}

#endif