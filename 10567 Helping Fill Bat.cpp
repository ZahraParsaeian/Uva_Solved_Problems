//#define Q10567
#ifdef  Q10567

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef map<char,int>mci;
typedef vector<vc> vci;

int main(){

    ios::sync_with_stdio(0);

    string a,queray;  int n;  char qu;
    while(cin>>a){
        vvi sc(52);  mci s,q,indf,indl;
        cin>>n;
        for (int j = 0; j < a.size(); ++j) {
            if(isupper(a[j]))
                sc[a[j]-65].push_back(j);
            else if(islower(a[j]))
                sc[a[j]-71].push_back(j);
        }
        for (int i = 0; i < n; ++i) {
            cin>>queray;
            bool check=true;
            int indx,first;
            if(isupper(queray[0])){
                if(sc[queray[0]-65].size()==0)
                    check=false;
            }
            else if(islower(queray[0])) {
                if (sc[queray[0]-71].size() == 0)
                    check = false;
            }
            if(check) {
                if(isupper(queray[0])){
                    indx = sc[queray[0]-65][0] ; first = sc[queray[0]-65][0];
                }
                else if(islower(queray[0])) {
                    indx = sc[queray[0]-71][0] ; first = sc[queray[0]-71][0];
                }
                for (int j = 1; j < queray.size(); ++j) {
                    if(isupper(queray[j])) {
                        if (sc[queray[j] - 65].size() == 0)
                            check = false;
                    }
                    else if(islower(queray[j])){
                        if(sc[queray[j]-71].size()==0)
                            check=false;
                    }
                    vi::iterator it;
                    if(check) {
                        if (isupper(queray[j])) {
                            int now = upper_bound(sc[queray[j] - 65].begin(), sc[queray[j] - 65].end(), indx) - sc[queray[j] - 65].begin();
                            if (sc[queray[j]-65][now] > indx) indx = sc[queray[j]-65][now];
                            else check = false;
                        }
                        else if (islower(queray[j])) {
                            int now = upper_bound(sc[queray[j] - 71].begin(), sc[queray[j] - 71].end(), indx) - sc[queray[j] - 71].begin();
                            if (sc[queray[j]-71][now] > indx) indx = sc[queray[j]-71][now];
                            else check = false;
                        }
                    }
                }
            }
            if(check)
                cout<<"Matched "<<first<<" "<<indx<<endl;
            else
                cout<<"Not matched\n";
        }
    }

    return 0;

}

#endif