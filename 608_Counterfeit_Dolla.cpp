//AC
//#define Q608
#ifdef Q608

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc;
    cin>>tc;
    while(tc--){
        string a,b,c;
        map<int,int>up;
        map<int,int>down;
        map<int,int>even;
        for(int j=0;j<3;j++){
            cin>>a>>b>>c;
            if(c=="even"){
                for(auto i:a)
                    even[i-64]++;
                for(auto i:b)
                    even[i-64]++;
            }
            else if(c=="up"){
                for(auto i:b)
                    up[i-64]++;
                for(auto i:a)
                    down[i-64]++;
            }
            else if(c=="down"){
                for(auto i:b)
                    down[i-64]++;
                for(auto i:a)
                    up[i-64]++;
            }
        }
        pair<char,pair<int,int>>ans;
        ans.second.first=ans.second.second=0;
        for(int i=1;i<=12;i++){
            if(even.count(i)==0){
                int maxx;
                char m;
                if(up[i]>=down[i]){
                    maxx=up[i];
                    m='u';
                }
                else{
                    maxx=down[i];
                    m='d';
                }
                if(maxx>ans.second.second){
                    ans.first=m;
                    ans.second.first=i;
                    ans.second.second=maxx;
                }
            }
        }
        cout<<char(ans.second.first+64)<<" is the counterfeit coin and it is ";
        if(ans.first=='u')
            cout<<"light.\n";
        else if(ans.first=='d')
            cout<<"heavy.\n";
    }

    return 0;
}


#endif

