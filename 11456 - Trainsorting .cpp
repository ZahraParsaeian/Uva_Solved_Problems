//#define Q11456
#ifdef Q11456

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int>vi;

int main(){

    ios::sync_with_stdio(0);

    int tc;  cin>>tc;
    while(tc--){
        int n;  cin>>n;
        vi nums(n);
        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
        }
        vi tailB(n),tailS(n);
        int ans=1e-9;
        for(int i=0;i<nums.size();i++) {
            int lenB=0,lenS=0;
            for (int j = i; j < nums.size(); ++j) {
                if(nums[j]>nums[i]){
                    int pos = lower_bound(tailB.begin(), tailB.begin() + lenB, nums[j]) - tailB.begin();
                    tailB[pos] = nums[j];
                    if (pos + 1 > lenB)
                        lenB = pos + 1;
                }
                else {
                    int srch = nums[j] * -1;
                    int pos = lower_bound(tailS.begin(), tailS.begin() + lenS, srch) - tailS.begin();
                    tailS[pos] = srch;
                    if (pos + 1 > lenS)
                        lenS = pos + 1;
                }
            }
            ans=max(lenB+lenS,ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}
/*
#include<bits/stdc++.h>

using namespace std;

int nums[2010], ld[2010], li[2010];

int main() {
    ios::sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        int n, ans = 0; cin >> n;
        for(int i = 0; i < n; i++) cin >> nums[i];
        for(int i = n - 1; i >= 0; i--) {
            li[i] = 1; ld[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) li[i] = max(li[i], li[j] + 1);
                else ld[i] = max(ld[i], ld[j] + 1);
            }
            ans = max(ans, ld[i] + li[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
 */


#endif