//#define Q10721
#ifdef Q10721

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vl;
typedef vector<vl> vvl;

vvl memo; int m;

long long BC( int n ,int k ){
    if(!n && !k) return 1;
    if(!k) return 0;
    if(n<0) return 0;
    if ( memo[n][k] != -1)  return memo[n][k];
    memo[n][k] = 0;
    for ( int i = 1 ; i <= m; i++) {
        memo[n][k] += BC(n - i, k - 1);
    }
    return memo[n][k];
}

int main(){

    ios::sync_with_stdio(0);

    int n,k;
    while(cin >> n >> k >> m){
        memo.clear(); memo.resize(n + 2, vl(k + 2 , -1));
        cout<< BC(n , k)<<endl;

    }
    return 0;
}

#endif