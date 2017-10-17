//#define Q443
#ifdef Q443

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

vll vec;
set<ll> s;
map <ll ,ll > m;

void fill () {
    vec.resize(5842);
    int n;
    int pos2,pos3,pos5,pos7;

    pos2=0;
    pos3=0;
    pos5=0;
    pos7=0;
    vec[0]=1;

    for(int i=1;i<5842;i++){
        vec[i]=min(min(2*vec[pos2],3*vec[pos3]),min(5*vec[pos5],7*vec[pos7]));
        if(vec[i]==2*vec[pos2]) pos2++;
        if(vec[i]==3*vec[pos3]) pos3++;
        if(vec[i]==5*vec[pos5]) pos5++;
        if(vec[i]==7*vec[pos7]) pos7++;
    }
}

int main(){

    ios::sync_with_stdio(0);

    int n;
    fill();
    while (cin >> n && n){
        if (n % 100 >= 11 && n % 100 <= 19)
            cout << "The "<<n<<"th humble number is "<<vec[n - 1]<<".\n";
        else if (n % 10 == 1)
            cout << "The "<<n<<"st humble number is "<<vec[n - 1]<<".\n";
        else if (n % 10 == 2)
            cout << "The "<<n<<"nd humble number is "<<vec[n - 1]<<".\n";
        else if ( n % 10 == 3)
            cout << "The "<<n<<"rd humble number is "<<vec[n - 1]<<".\n";
        else
            cout << "The "<<n<<"th humble number is "<<vec[n - 1]<<".\n";
    }

    return 0;
}

#endif