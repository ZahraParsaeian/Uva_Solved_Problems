//#define Q11849
#ifdef Q11849

//AC

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int m,n,a;
    while(cin>>n>>m && (m || n)){
        map<int,bool> check;
        for(int i=0;i<n;i++){
            cin>>a;
            check[a]=true;
        }
        int cont=0;
        for(int i=0;i<m;i++){
            cin>>a;
            if(check[a])
                cont++;
        }
        cout<<cont<<endl;
    }

    return 0;
}

#endif