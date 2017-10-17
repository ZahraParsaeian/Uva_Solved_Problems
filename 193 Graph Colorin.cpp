//#define Q193
#ifdef Q193

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int m,k,mx;
vvi vec(m,vi(m));
vi color(m),ans;

void check(int i){
    for (int l = i; l < vec.size(); ++l) {
        bool yes = true;
        for (int j = 0; j < vec[l].size(); ++j) {
            if (color[vec[l][j]] == 1)
                yes = false;
        }
        if (yes) {
            color[l] = 1;
            check(i + 1);
            color[l] = 0;
            check(i + 1);
        }
        else{
            color[l]=0;
            check(i+1);
        }

    }
    int sum=0;
    for(int d=0;d<color.size();d++){
        if(color[i])   sum++;
    }
    if(sum>mx){
        ans.clear();
        for(int d=0;d<color.size();d++){
            if(color[i])   ans.push_back(i);
        }
        mx=sum;
    }
}

int main(){

    ios::sync_with_stdio(0);

    int tc;
    cin>>tc;
    while(tc--){
        cin>>m>>k;
        mx=0;
        vec.assign(m,vi(m));
        color.assign(m,0);
        int f,s;
        for (int i = 0; i < k; ++i) {
            cin>>f>>s;
            vec[f-1].push_back(s-1);
            vec[s-1].push_back(f-1);
        }
        check(0);
        cout<<mx<<endl;
        for(int i=0;i<ans.size()-1;i++) cout<<ans[i]<<" ";
        cout<<ans[ans.size()-1]<<endl;
    }
}

#endif