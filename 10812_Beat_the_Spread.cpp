#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ios::sync_with_stdio(0);

    int tc;
    ll s,d;
    cin>>tc;
    while(tc--){
        bool check=0;
        cin>>s>>d;
        if(s<d)
            cout<<"impossible\n";
        else {
            ll sum=s+d;
            if(sum%2)
                cout<<"impossible\n";
            else {
                ll a=sum/2;
                ll b=s-a;
                cout<<a<<" "<<b<<endl;

            }
        }
    }

    return 0;
}