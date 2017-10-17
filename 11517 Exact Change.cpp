//#define Q11517
#ifdef Q11517

//AC

#include<bits/stdc++.h>

using namespace std;

#define inf 100001000
#define MAX 40000

typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int tc,n,value;  cin>>tc;
    while(tc--){
        cin>>value>>n;
        vi val(n);
        for (int i = 0; i < n; ++i) {
            cin>>val[i];
        }
        vi dp(MAX,INT_MAX);
        dp[0] = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = MAX - val[j] - 1; i >= 0 ; --i) {
                if(dp[i] < INT_MAX)
                    dp[i+val[j]] = min(dp[i+val[j]] , dp[i]+1);
            }
        }
        for (int k = value; k <= MAX; ++k) {
            if(dp[k] != INT_MAX) {
                cout << k << " " << dp[k] << endl;
                break;
            }
        }
    }

    return 0;
}

#endif