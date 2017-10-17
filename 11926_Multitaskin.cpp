//#define Q11926
#ifdef Q11926

//AC

#include<bits/stdc++.h>

using namespace std;

bool ok(int i,int j,int *mp){
    for(int k=i;k<j;k++){
        if(mp[k]==false)
            mp[k]=true;
        else
            return 1;
    }
    return 0;
}

int main(){

    ios::sync_with_stdio(0);

    int n,m,f,s,t;
    while(cin>>n>>m && (n || m)){
        int mp[1000010]={0};
        int check=0;
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>f>>s;
            if(!check && ok(f,s,mp))
                check=1;
        }
        for(int i=0;i<m;i++){
            cin>>f>>s>>t;
            while(f<=1000000 && !check){
                if(ok(f,s,mp))
                    check=1;
                f+=t;
                s+=t;
                if(s>1000000)
                    s=1000000;
            }
        }
        if(!check)
            cout<<"NO CONFLICT\n";
        else
            cout<<"CONFLICT\n";
    }

    return 0;

}

#endif