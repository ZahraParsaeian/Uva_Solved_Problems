// In his name

//AC

//#define Q10976
#ifdef Q10976

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

//int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){

    ios::sync_with_stdio(0);

    int k;
    while(cin>>k){
        //int j=k*3;
        set<ii>vec;
        for(int i=3;i<=k+1;i++){
            for(int j=1;j<=i/2;j++){
                if((i*k)%j==0 && (i*k)%(i-j)==0){
                    vec.insert(make_pair((i*k)/j,(i*k)/(i-j)));
                }
            }
        }
        vec.insert(ii(k*2,k*2));
        cout<<vec.size()<<endl;
        set<ii>::iterator i;
        i=vec.end();
        i--;
        for(int j=0;j<vec.size();j++){
            cout << 1 << "/" << k << " = " <<1<<"/"<<i->first<<" + "<<1<<"/"<<i->second<<endl;
            i--;
        }
    }


    return 0;
}

#endif