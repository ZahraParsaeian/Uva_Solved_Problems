//#define Q10459
#ifdef Q10459

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef  stack<int> si;
typedef queue<int> qi;
typedef map<int,int> mii;
#define inf 1e9
#define sup 1e-9

vi vis;
vvi vec;
int mx;

void dfs (int v , int d){
    vis[v] = 1;
    for (auto i : vec[v])
        if(!vis[i]){
            mx = max (mx , d + 1);
            dfs(i , d + 1);
        }
}

void find(int v , int d , vi & tmp){
    vis[v] = 1;
    for (auto i : vec[v]){
        if (!vis[i]) {
            if (d + 1 == mx) tmp[i] = 1;
            find(i , d + 1 , tmp);
        }
    }
}

int main(){

    ios::sync_with_stdio(0);

    int n , num , a;
    while (cin >> n){
        vec.clear(); vec.resize(n);
        vis.clear(); vis.resize(n , 0);
        for (int i = 0; i < n; ++i) {
            cin >> num;
            for (int j = 0; j < num; ++j) {
                cin >> a;
                vec[i].push_back(a - 1);
            }
        }
        int lvl = 1 , rem = n;
        vi choose(n , 0);
        while (lvl++){
            for (int i = 0; i < n; ++i) {
                if (!choose[i]){
                    int par = 0;
                    for (auto j : vec[i]) if (choose[j] == lvl || !choose[j]) par++;
                    if (par == 1) choose[i] = lvl , rem--;
                }
            }
            if (rem == 1 || rem == 2) break;
        }
        vi best , worst;
        for (int i = 0; i < n; ++i)
            if (!choose[i]) best.push_back(i);
        int ans = - inf;
        for (auto i : best){
            vis.clear(); vis.resize(n , 0);
            mx = - inf;
            dfs(i , 0);
            ans = max (mx , ans);
        }
        mx = ans;
        vi tmp (n , 0);
        for (auto i : best) {
            vis.clear(); vis.resize(n , 0);
            find(i , 0 , tmp);
        }
        for (int i = 0 ; i < n ; i++)
            if (tmp[i]) worst.push_back(i);
        sort(best.begin() , best.end());
        sort(worst.begin(), worst.end());
        cout <<"Best Roots  :";
        for (int i = 0; i < best.size(); i++)
            cout <<" "<< best[i] + 1;
        cout << endl;
        cout << "Worst Roots :";
        for (int i = 0; i < worst.size(); i++)
            cout <<" "<< worst[i] + 1;
        cout << endl;
    }

    return 0;
}

#endif