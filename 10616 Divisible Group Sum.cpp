//#define Q10616
#ifdef Q10616

//AC

#include <bits/stdc++.h>

using namespace std;

#define inf 100001000

typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<vvi>vvvi;

vvvi memo;vi vec;

int n,q,m,d;

int choose(int M,long long sum,int indx){
    int mod=((sum % d) + d) % d;
    if(M == m) return(mod == 0 ? 1 : 0);
    if(memo[indx][mod][M] != -inf) return memo[indx][mod][M];
    memo[indx][mod][M]=0;
    for (int i = indx ; i < vec.size(); ++i) {
        memo[indx][mod][M] += choose(M+1,(sum+ vec[i]),i+1);
    }
    return memo[indx][mod][M];
}

int main(){

    ios::sync_with_stdio(0);

    int cont=1;
    while(cin>>n>>q && (n || q)){
        cout<<"SET "<<cont++<<":\n";
        vec.clear(),vec.assign(n,0);
        for (int i = 0; i < n; ++i) {
            cin>>vec[i];
        }
        for (int j = 0; j < q; ++j) {
            cin>>d>>m;
            memo.clear();
            memo.assign(n+2,vvi(d+2,vi(m+2,-inf)));
            cout<< "QUERY "<<j+1<<": ";
            cout<<choose(0,0,0)<<endl;
        }
    }

    return 0;
}

#endif