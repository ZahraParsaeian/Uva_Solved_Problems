//#define Q12247
#ifdef Q12247

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);


    int a,b,c,d,e;
    while(cin>>a>>b>>c>>d>>e && (a || b || c || d || e)){
        vi check(53,0);
        check[a]=1,check[b]=1,check[c]=1,check[d]=1,check[e]=1;
        vi f;
        f.push_back(a),f.push_back(b),f.push_back(c);
        sort(f.begin(),f.end());
        vi s;
        s.push_back(d),s.push_back(e);
        sort(s.begin(),s.end());
        if(s[1]>f[2]){
            if(s[0]>f[2]){
                int w=1;
                while(check[w])
                    w++;
                if(w==53)
                    cout<<-1<<endl;
                else
                    cout<<w<<endl;
            }
            else if(s[0]>f[1]){
                int w=f[1]+1;
                while(check[w]==1)
                    w++;
                if(w==53)
                    cout<<-1<<endl;
                else
                    cout<<w<<endl;
            }
            else{
                int w=f[2]+1;
                while(check[w]==1)
                    w++;
                if(w==53)
                    cout<<-1<<endl;
                else
                    cout<<w<<endl;
            }
        }
        else{
            if(s[0]>f[1]){
                int w=f[1]+1;
                while(check[w]==1)
                    w++;
                if(w==53)
                    cout<<-1<<endl;
                else
                    cout<<w<<endl;
            }
            else
                cout<<-1<<endl;
        }

    }

    return 0;
}

#endif