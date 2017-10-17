//#define Q10189
#ifdef Q10189

//AC

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int a1[]={-1,0,1,-1,+1,-1,0,1};
    int a2[]={-1,-1,-1,0,0,1,1,1};
    int n,m;
    int cont=1;
    while(cin>>n>>m && (m || n)){
        if(cont>1)
            cout<<endl;
        //vector<vector<char>>vec(n,vector<char>(m));
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char a;
                cin>>a;
                if(a=='*') {
                    ans[i][j] = -1;
                    for(int z=0;z<8;z++){
                        if(i+a1[z]>=0 && i+a1[z]<=n-1 && j+a2[z]>=0 && j+a2[z]<=m-1){
                            if(ans[i+a1[z]][j+a2[z]]!=-1)
                                ans[i+a1[z]][j+a2[z]]++;
                        }
                    }
                }
            }
        }
        cout<<"Field #"<<cont++<<":\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==-1)
                    cout<<'*';
                else
                    cout<<ans[i][j];
            }

            cout<<endl;
        }
    }

    return 0;
}

#endif