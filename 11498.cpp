//In the name of allah
#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int k ,n,m,x,y;
    while(cin>>k && k){
        //cerr<<"k  "<<k<<endl;
        cin>>n>>m;
        while(k--){
            cin>>x>>y;
            if(x==n || y==m)
                cout<<"divisa\n";
            else if(x>n && y>m)
                cout<<"NE\n";
            else if(x>n && y<m)
                cout<<"SE\n";
            else if(x<n && y>m)
                cout<<"NO\n";
            else if(x<n && y<m)
                cout<<"SO\n";
        }
    }

    return 0;
}