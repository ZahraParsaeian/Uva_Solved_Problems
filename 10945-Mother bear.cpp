//#define Q10945
#ifdef Q10945

//AC

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    stringstream str;
    string a;
    while(getline(cin,a)) {
        if (a == "DONE")
            break;
        str.clear();
        str << a;
        vector<char> vec;
        char b;
        while (str >> b) {
            if (((b - 64) >= 1 && (b - 64) <= 26) || ((b - 64) >= 33 && (b - 64) <= 58)) {
                b=tolower(b);
                vec.push_back(b);
            }
        }
        bool check=true;
        for (int i = 0; i < vec.size() / 2; i++) {
            if(vec[i] != vec[vec.size()-i-1]) {
                cout << "Uh oh.." << endl;
                check=false;
                break;
            }
        }
        if(check)
            cout<<"You won't be eaten!\n";
    }

    return 0;
}

#endif