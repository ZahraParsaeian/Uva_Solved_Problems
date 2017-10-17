//#define Q10264
#ifdef Q10264

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int n;
    while(cin>>n){
        int a=pow(2,n);
        vi vec(a);
        for(int i=0;i<a;i++){
            cin>>vec[i];
        }
        vi pot(a);
        for(int i=0;i<a;i++){
            string s=bitset<15>(i).to_string();
            //cout<<"i   "<<i<<endl;
            //cout<<"s  "<<s<<endl;
            int sum=0;
            for(int j=0;j<n;j++){
                string d=s;
                if(d[s.size()-j-1]=='1')
                    d[s.size()-j-1]='0';
                else if(d[s.size()-j-1]=='0')
                    d[s.size()-j-1]='1';
                //cout<<"d  "<<d<<endl;
                //cout<<"bitset<15>(d).to_ulong()     "<<bitset<15>(d).to_ulong()<<endl;
                sum+=vec[bitset<15>(d).to_ulong()];
            }
            pot[i]=sum;
            //cout<<"sum  "<<sum<<endl;
        }
        int maxx=-1000;
        for(int i=0;i<a;i++){
            string s=bitset<15>(i).to_string();
            for(int j=0;j<n;j++){
                string d=s;
                if(d[s.size()-j-1]=='1')
                    d[s.size()-j-1]='0';
                else if(d[s.size()-j-1]=='0')
                    d[s.size()-j-1]='1';
                int f=pot[i]+pot[bitset<15>(d).to_ulong()];
                maxx=max(maxx,f);

            }
        }
        cout<<maxx<<endl;
    }

    return 0;
}

#endif