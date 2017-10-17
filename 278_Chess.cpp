#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc,n,m;
    char a;
    cin>>tc;
    while(tc--){
        cin>>a>>n>>m;
        int mx=max(m,n);
        int mn=min(m,n);
        if(a=='r' || a=='Q') {
            cout<<mn<<endl;
        }
        else if(a=='k'){
            if(mx%2)
                mx+=1;
            cout<<(mx/2)*mn<<endl;
        }
        else if(a=='K'){
            if(mx%2)
                mx+=1;
            if(mn%2)
                mn+=1;
            cout<<(mn/2)*(mx/2)<<endl;
        }
    }

    return  0;
}