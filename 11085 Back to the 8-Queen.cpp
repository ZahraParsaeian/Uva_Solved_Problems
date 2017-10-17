//#define Q11085
#ifdef Q11085

//AC

#include<bits/stdc++.h>

using namespace std;

vector<int>vec1(8),vec(8);
int ans;

bool can(int r,int c){
    for (int i = 0; i < c; ++i)
        if(vec1[i]==r || (abs(vec1[i]-r)==abs(i-c)) )
            return false;
    return true;
}

void fill(int c){
    if(c==8){
        int sum=0;
        for (int i = 0; i < 8; ++i)
            if(vec1[i]!=vec[i])  sum++;
        ans=min(ans,sum);
    }
    for (int j = 0; j < 8; ++j) {
        if(can(j,c)) {
            vec1[c] = j; fill(c + 1);
        }
    }
}

int main(){

    ios::sync_with_stdio(0);

    int n,Case=1;
    while(cin>>n){
        ans=1e9;
        vec[0]=n-1;
        for (int i = 1; i < 8; ++i) {
            cin>>n;
            vec[i]=n-1;
        }
        fill(0);
        cout<<"Case "<<Case++<<": "<<ans<<endl;
    }

    return 0;
}

#endif