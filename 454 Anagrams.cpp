//#define Q454
#ifdef Q454

//AC

#include<bits/stdc++.h>

using namespace std;

string brk(string a){
    string b(a);
    b.erase(remove(b.begin(),b.end(),' '),b.end());
    sort(b.begin(),b.end());
    return b;
}

int main(){

    ios::sync_with_stdio(0);

    int tc;
    cin>>tc;
    string a;
    getline(cin,a);
    getline(cin,a);
    while(tc--){
        vector<string>vec;
        while(getline(cin,a) && a.length()!=0) {
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                string f=brk(vec[i]);
                string s=brk(vec[j]);
                if(f==s)
                    cout<<vec[i]<<" = "<<vec[j]<<endl;
            }
        }
        if(tc)
            cout<<endl;
    }
    return 0;
}
#endif