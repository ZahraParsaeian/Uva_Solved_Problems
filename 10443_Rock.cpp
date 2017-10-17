//#define Q10443
#ifdef Q10443

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main(){

    ios::sync_with_stdio(0);

    int tc,r,c,n;
    cin>>tc;
    int a1[]={-1,0,1,0};
    int a2[]={0,1,0,-1};
    int cont=0;
    while(tc--){
        if(cont++)
            cout<<endl;
        cin>>r>>c>>n;
        vvc vec(r,vc(c));
        vvc vec2(r,vc(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>vec[i][j];
            }
        }
        bool check;
        for(int k=0;k<n;k++){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    check=false;
                    for(int z=0;z<4;z++){
                        if(a1[z]+i>=0 && a1[z]+i<=r-1 && a2[z]+j>=0 && a2[z]+j<=c-1){
                            if(vec[i][j]=='R' && vec[i+a1[z]][j+a2[z]]=='P') {
                                vec2[i][j] = 'P';
                                check = 1;
                                break;
                            }
                            else if(vec[i][j]=='S' && vec[i+a1[z]][j+a2[z]]=='R') {
                                vec2[i][j] = 'R';
                                check = true;
                                break;
                            }
                            else if(vec[i][j]=='P' && vec[i+a1[z]][j+a2[z]]=='S') {
                                vec2[i][j] = 'S';
                                check = true;
                                break;
                            }
                        }
                    }
                    if(!check)
                        vec2[i][j]=vec[i][j];
                }
            }
            vec=vec2;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<vec2[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}

#endif