//#define Q11988
#ifdef Q11988

//AC

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    char c;
    list<char>text;
    list<char>::iterator i;
    bool check=false;
    string a;
    while((c=getchar()) != EOF){
        if(c !='\n'){
            if(c=='[') {
                check = true;
                i = text.begin();
            }
            else if(c==']')
                check=false;
            else{
                if(check)
                    text.insert(i,c);
                else
                    text.push_back(c);
            }
        }
        else {
            i=text.begin();
            for (i;i!=text.end();i++) {
                cout << *i;
            }
            cout << endl;
            //puts("");
            //i=text.begin();
            text.clear();
            //check = false;
        }
    }

    return 0;
}

#endif