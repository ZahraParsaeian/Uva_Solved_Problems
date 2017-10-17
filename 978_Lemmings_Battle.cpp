//#define Q978
#ifdef Q978

//AC

#include<bits/stdc++.h>

using namespace std;

typedef priority_queue<int> pqi;
typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int tc,bf,g,b;
    cin>>tc;
    while(tc--){
        cin>>bf>>g>>b;
        pqi gs;
        vi gv;
        pqi bs;
        vi bv;
        int a;
        for(int i=0;i<g;i++) {
            cin >> a;
            gs.push(a);
        }
        for(int i=0;i<b;i++) {
            cin >> a;
            bs.push(a);
        }
        while(!gs.empty() && !bs.empty()) {
            int tmp=min(gs.size(),bs.size());
            tmp=min(bf,tmp);
            for (int n = 0; n < tmp; n++) {
                int a=bs.top(); bs.pop();
                int b=gs.top();gs.pop();
                if(a>b)
                    bv.push_back(a-b);
                else if(b>a)
                    gv.push_back(b-a);
            }
            for(auto i:gv)
                gs.push(i);
            for(auto i:bv)
                bs.push(i);
            gv.clear();
            bv.clear();

        }
        if(!bs.empty()){
            cout<<"blue wins\n";
            while(!bs.empty()){
                cout<<bs.top()<<endl;
                bs.pop();
            }
        }
        else if(!gs.empty()){
            cout<<"green wins\n";
            while(!gs.empty()){
                cout<<gs.top()<<endl;
                gs.pop();
            }
        }
        else
            cout<<"green and blue died\n";
        if(tc)
            cout<<endl;

    }

    return 0;
}

#endif