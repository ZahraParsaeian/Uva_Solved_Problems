//#define Q11413
#ifdef Q11413

//AC

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    int m,n;
    while(cin>>n>>m){
        vector<int>vec(n);
        int kol=0;
        for (int i = 0; i < n; ++i) {
            cin>>vec[i];
            kol+=vec[i];
        }
        int high=1000000010,low=0,mid,final=1000000001;
        while(low+1<high){
            mid=(high+low)/2;
            int sum=0,cont=0,tedad=0;
            bool check=false;
            vector<int>ans;
            for (int i = 0; i < vec.size(); ) {
                if (sum + vec[i] <= mid) {
                    sum += vec[i];
                    ans.push_back(sum);
                    tedad++;
                    i++;
                    if (!check) {
                        cont++;
                        check = true;
                    }
                }
                else if (sum == 0 && vec[i] > mid) i++;
                else {
                    //ans.push_back(sum);
                    sum = 0;
                    check = false;
                }

            }
            if(cont>m || tedad<vec.size())
                low=mid;
            else {
                high = mid;
                int a=1e-9;
                    for (int i = 0; i < ans.size(); ++i)
                        a = max(a, ans[i]);
                    final = min(a, final);

            }
        }
        cout<<final<<endl;
    }

    return 0;
}

#endif