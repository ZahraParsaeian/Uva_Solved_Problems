//#define Q11057
#ifdef Q11057

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int n,money;
    while(cin>>n){
        vi cost(n);
        for (int i = 0; i <n; ++i) {
            cin>>cost[i];
        }
        cin>>money;
        sort(cost.begin(),cost.end());
        int f=0,s=10000000;
        for (int j = 0; j <n; ++j) {
            if(binary_search(cost.begin(),cost.end(),money-cost[j])) {
                if (abs(money - (cost[j] * 2)) < (s - f))
                    f = cost[j], s = money - cost[j];
            }
        }
        cout<<"Peter should buy books whose prices are "<<f<<" and "<<s<<".\n";
        cout<<endl;
    }

    return 0;
}

#endif