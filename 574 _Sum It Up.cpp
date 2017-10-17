//In his name

//#define Q574
#ifdef Q574

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int sum,Size,n;
vi ans,tmp(12),nums(12),vis;
set<vi>answer;
bool shod;

void iseq(int i,int j,int cur) {
    if (cur == Size) {
        vi ans;
        for (int k = 0; k <= i; ++k) {
            ans.push_back(tmp[k]);
        }
        sort(ans.rbegin(), ans.rend());
        answer.insert(ans);
        //return;
    }
    for (int l = j + 1; l < n; ++l) {
        if (nums[l] + cur <= Size) {
            tmp[i + 1] = nums[l];
            iseq(i + 1, l, cur + nums[l]);
        }
    }
}

int main(){

    ios::sync_with_stdio(0);

    while(cin>>Size>>n && (Size || n)){
        answer.clear();
        for (int i = 0; i < n  ; ++i) {
            cin>>nums[i];
        }
        for(int i=0 ;i<n;i++){
            tmp[0]=nums[i];
            sum=0;
            //ans.clear();
            iseq(0,i,nums[i]);
        }
        cout<<"Sums of "<<Size<<":\n";
        if(answer.size()) {
            set<vi>::reverse_iterator i;
            i=answer.rbegin();
            for(;i!=answer.rend();i++) {
                int j=0;
                for (; j < i->size() - 1; ++j) {
                    cout << (*i)[j]<<"+";
                }
                cout<< (*i)[j]<<endl;
            }
        } else  cout<<"NONE\n";
    }

    return 0;
}

#endif