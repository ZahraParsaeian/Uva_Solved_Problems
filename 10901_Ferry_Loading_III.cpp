//#define Q10901
#ifdef Q10901

//AC

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef queue<ii> qii;
typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int tc,n,t,m,a;
    string b;
    cin>>tc;
    while(tc--){
        cin>>n>>t>>m;
        qii right;
        qii left;
        vi ans(m);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            if(b=="right")
                right.push(ii(a,i));
            else if(b=="left")
                left.push(ii(a,i));
        }
        int time=0;
        string first="left";
        while(!right.empty() || !left.empty()){
            if(first=="right"){
                int h=0;
                while(h+1<=n  && !right.empty() && right.front().first<=time) {
                    h++;
                    //cout << time + t << endl;
                    ans[right.front().second]=time+t;
                    right.pop();
                    first = "left";
                }
                if(!h){
                    if(right.empty() || (!left.empty() && left.front().first<right.front().first)){
                        if(left.front().first>time)
                            time=left.front().first;
                        first="left";
                    }
                    else if(left.empty() || right.front().first<=left.front().first){
                        time=right.front().first;
                        continue;
                    }
                }
            }
            else if(first=="left"){
                int h=0;
                while(h+1<=n  && !left.empty() && left.front().first<=time) {
                    h++;
                    //cout << time + t << endl;
                    ans[left.front().second]=time+t;
                    left.pop();
                    first = "right";
                }
                if(!h){
                    if(left.empty() || (!right.empty() && right.front().first<left.front().first)){
                        if(right.front().first>time)
                            time=right.front().first;
                        first="right";
                    }
                    else if(right.empty() || left.front().first<=right.front().first){
                        time=left.front().first;
                        continue;
                    }
                }
            }
            time+=t;
        }
        for(auto i:ans)
            cout<<i<<endl;
        if(tc)
            cout<<endl;
    }

    return 0;
}

#endif