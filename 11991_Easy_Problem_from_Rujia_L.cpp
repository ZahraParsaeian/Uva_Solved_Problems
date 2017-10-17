//#define Q11991
#ifdef Q11991

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

    ios::sync_with_stdio(0);

    int n,m;
    while(cin>>n>>m){
        vvi vec(1000020);
        int d;
        for(int i=0;i<n;i++){
            cin>>d;
            vec[d].push_back(i+1);
        }
        for(int i=0;i<m;i++){
            int k,v;
            cin>>k>>v;
            if(vec[v].size()<k)
                cout<<0<<endl;
            else
                cout<<vec[v][k-1]<<endl;
        }
    }

    return 0;
}


#endif