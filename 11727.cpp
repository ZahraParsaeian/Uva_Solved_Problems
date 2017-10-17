//In his name
#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int tc,x,y,z;
    cin>>tc;
    vector<int>vec;
    int cont=1;
    while(tc--){
        cin>>x>>y>>z;
        vec.push_back(x);
        vec.push_back(y);
        vec.push_back(z);
        sort(vec.begin(),vec.end());
        cout<<"Case "<<cont++<<": "<<vec[1]<<endl;
        vec.clear();
    }

    return 0;
}