//#define Q10819
#ifdef Q10819

//AC

#include <bits/stdc++.h>

using namespace std;

#define inf 1000000100
typedef vector<int>vi;
typedef vector<vi>vvi;

vi wt,val;
vvi memo;
int n,w;

int sol(int indx,int W){
    if(indx == n) {
        int a = w + 200 - W;
        if(a > w && a <= 2000)  return INT_MIN;
        return 0;
    }
    if(memo[indx][W] != -1) return memo[indx][W];
    if(W - wt[indx] >= 0)
        return memo[indx][W] = max(sol(indx + 1 , W) , val[indx] + sol(indx + 1 , W - wt[indx]));
    else
        return memo[indx][W]=sol(indx+1,W);
}

int main(){

    ios::sync_with_stdio(0);

    while(cin>>w>>n){
        wt.clear(); wt.assign(n,0);
        val.clear(); val.assign(n,0);
        for (int i = 0; i < n; ++i) {
            cin>>wt[i]>>val[i];
        }
        memo.clear(); memo.assign(n+2,vi(w+210,-1));
        cout<<sol(0,w+200)<<endl;
    }

    return 0;
}

#endif