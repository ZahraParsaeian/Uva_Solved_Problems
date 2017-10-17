#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int n,m;
    while(cin>>n>>m && (m || n)){
        int mx = max(m,n);
        int mn = min(m,n);
        if(n==1) {
            cout<<m<<" knights may be placed on a 1 row "<<m<<" column board."<<endl;
        }
        else if(m==1) {
            cout<<n<<" knights may be placed on a "<<n<<" row 1 column board.\n";
        }
        else if(n==2) {
            if(m%4==0){
                cout<<m<<" knights may be placed on a 2 row "<<m<<" column board."<<endl;
            }
            else if(m%4==2 || m%4==3){
                cout<<((m/4)+1)*4<<" knights may be placed on a 2 row "<<m<<" column board."<<endl;
            }
            else if(m%4==1)
                cout<<m+1<<" knights may be placed on a 2 row "<<m<<" column board."<<endl;
        }
        else if(m==2) {
            if(n%4==0){
                cout<<n<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
            }
            else if(n%4==2 || n%4==3){
                cout<<((n/4)+1)*4<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
            }
            else if(n%4==1)
                cout<<n+1<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }
        else{
            int result=0;
            for(int i=1 ; i<=mn ; i++){
                result+=(mx + (i%2))/2;
            }
            cout<<result<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }
        // my problem is in 2 and 1
    }

    return 0;
}