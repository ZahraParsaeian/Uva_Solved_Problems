//#define Q787
#ifdef Q787

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll>vll;

int main(){

    ios::sync_with_stdio(0);

    string a;
    while(getline(cin,a)){
        vll pro;
        ll n;
        int cont=0;
        stringstream str(a);
        ll sum=1,mx=-999999;
        while(str>>n){
            if(n!=-999999) {
                cont++;
                if(n) {
                    sum *= n;
                    pro.push_back(sum);
                    mx = max(sum, mx);
                }
                else{
                    sum=1;
                    pro.push_back(n);
                    mx=max(mx,n);
                }
            }
        }
        for (int i = 0; i < cont; ++i) {
            for (int j = i+1; j < cont; ++j) {
                if(pro[i] && pro[j])
                     mx=max(mx,pro[j]/pro[i]);
            }
        }
        cout<<mx<<endl;
    }
}

#endif