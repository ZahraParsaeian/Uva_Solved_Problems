//#define Q11034
#ifdef Q11034

//AC

#include<bits/stdc++.h>

using namespace std;

typedef queue<int> qi;

int main(){

    ios::sync_with_stdio(0);

    int tc,l,n,a;
    string dir;
    cin>>tc;
    while(tc--){
        cin>>l>>n;
        l*=100;
        qi left;
        qi right;
        string first="left";
        for(int i=0;i<n;i++){
            cin>>a>>dir;
            if(dir=="left"){
                left.push(a);
            }
            else if(dir=="right"){
                right.push(a);
            }
        }
        int cont=0;
        //int lf=l;
        while(!right.empty() || !left.empty()){
            //lf=l;
            if(first=="right") {
                int sum=0;
                while((sum + right.front())<=l && !right.empty()){
                //while (lf >= right.front() && !right.empty()) {
                    //lf -= right.front();
                    sum+=right.front();
                    right.pop();
                }
                first = "left";
            }

            else if(first=="left"){
                int sum=0;
                while((sum + left.front())<=l && !left.empty()){
                //while(lf>=left.front() && !left.empty()){
                    sum+=left.front();
                    //lf-=left.front();
                    left.pop();
                }
                first="right";
            }
            cont++;
        }
        cout<<cont<<endl;

    }

    return 0;
}

#endif