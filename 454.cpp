//454 Anagrams
#define Q454
#ifdef Q454

#include<bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    cin.ignore();
    string str;
    while(tc --){
        cin.ignore();
        while(getline(cin,str) && str.length()!= 0){
            sort(str.rbegin(),str.rend());
            remove_if(str.begin(),str.end(),isspace);
            cout << str << "000" <<endl;
        }


    }

    return 0;
}


#endif