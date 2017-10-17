//#define Q10699
#ifdef Q10699

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
typedef unsigned long long ull;
#define inf 1000000000
#define sup 1e-9f

vi vec(1000010 , 0);

void fill(){
    for (int i = 2; i < 1000010; i++)
        if (vec[i] == 0)
            for (int j = i; j < 1000010; j += i)
                vec[j]++;
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    fill();
    while (cin >> n && n)
        cout << n << " : " << vec[n] << endl;

    return 0;
}

#endif