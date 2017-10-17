//#define Q10226
#ifdef Q10226

//AC

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc;
    cin>>tc;
    string a;
    getline(cin,a);
    getline(cin,a);
    while(tc--){
        map<string,double> m;
        double cont=0;
        while(getline(cin,a) && a.length()!=0){
            m[a]++;
            cont++;
        }
        map<string,double>::iterator i;
        for(i=m.begin();i!=m.end();i++){
            double s=(i->second/cont)*100;
            cout<<i->first<<" "<<fixed<<setprecision(4)<<s<<endl;
        }
        if(tc)
            cout<<endl;
    }

    return 0;
}

#endif