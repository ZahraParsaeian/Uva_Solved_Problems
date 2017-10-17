#define Q701
#ifdef Q701

//Ac

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
#define ma 1e7

int numofdigits(double n){
    int ans = 0;
    while (n){
        ans++;
        n /= 10;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(0);

     int n;
    while (cin >> n){
       /*double i = 1 ;
        int num = to_string(n).size();
        double k = -1;
        for (int i = 1; i < 1e7 ; i++){
            int num1 = to_string((int)pow(2.0 , i)).size();

            if ( num1 > num * 2){
                if(int(pow (2.0 , i) / pow (10.0 , num1 - num )) == n){
                    k = i;
                    break;
                }
            }
        }
        if (k == -1) cout << "no power of 2\n";
        else cout << k << endl;*/
        double f = log2(n) , s = log2(n + 1) , mul = log2(10);
        int k = -1;
        int a = numofdigits(n) + 1;
        for (int i = a; i < ma; ++i) {
            if (floor(s + i * mul) >= ceil(f + i * mul)){
                k = ceil(f + i * mul);
                break;
            }
        }
        if (k == -1) cout << "no power of 2\n";
        else cout << k << endl;
    }
    return 0;
}

#endif