//#define Q11286
#ifdef Q11286

//AC

#include<bits/stdc++.h>

using namespace std;

typedef set<int> si;
typedef vector<si> vsi;
typedef map<si,int> msi;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while(cin>>n && n){
        vsi vec(n);
        si s;
        msi m;
        for(int j=0;j<n;j++) {
            s.clear();
            for (int i = 0; i < 5; i++) {
                int a;
                cin >> a;
                s.insert(a);
            }
            m[s]++;
        }
        msi::iterator i;
        int maxx=0;
        for(i=m.begin();i!=m.end();i++){
            maxx=max(maxx,i->second);
        }
        //msi::iterator ii;
        int ans=0;
        for(i=m.begin();i!=m.end();i++){
            if(maxx==i->second)
                ans+=maxx;
        }
        cout<<ans<<endl;

    }

    return 0;
}

#endif