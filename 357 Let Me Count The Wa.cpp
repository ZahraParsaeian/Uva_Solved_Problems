//#define Q357
#ifdef Q357

//AC

#include <bits/stdc++.h>

using  namespace std;

vector<vector<long long>>memo;
vector<int>val;

long long ways(int type,int value){
    if(value == 0) return 1;
    if(value < 0 || type == 5) return 0;
    if(memo[type][value] != -1)  return memo[type][value];
    return memo[type][value] = ways(type , value - val[type]) + ways(type + 1 , value);
}

int main(){

    ios::sync_with_stdio(0);

    val.push_back(1),val.push_back(5),val.push_back(10),val.push_back(25),val.push_back(50);
    int n;
    memo.assign(6,vector<long long>(30001,-1));
    while(cin >> n){
        long long ans;
        ans = ways(0,n);
        if(ans!=1)
            cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change.\n";
        else
            cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
    }

    return 0;
}

#endif