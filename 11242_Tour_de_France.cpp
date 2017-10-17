//In his name

//#define Q11242
#ifdef Q11242

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n,m;
    int f[11];
    while(cin>>n && n){
        memset(f,0,sizeof(f));
        cin>>m;
        for(int i=0;i<n;i++){
            cin>>f[i];
        }
        int a;
        vector<double>s;
        for(int i=0;i<m;i++){
            cin>>a;
            for(int j=0;j<n;j++)
                s.push_back(a/f[j]);
        }
        double mx=0;
        sort(s.begin(),s.end());
        for(int i=0;i<s.size()-1;i++){
            mx=max(mx,s[i+1]/s[i]);
        }
        cout<<fixed<<setprecision(2)<<mx<<endl;
    }

    return 0;
}

#endif