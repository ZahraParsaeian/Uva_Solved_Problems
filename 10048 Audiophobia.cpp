//#define Q10048
#ifdef Q10048

//AC

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<pair<int,ii>> vec;
vector<vector<ii>> ans;
vi p , vis;
int c,s,q,answ;

void union_find(){
    for (int i = 0; i < c; ++i)
        p[i] = i;
}

int find_set(int i){
    return (p[i] == i) ? i : p[i] = find_set(p[i]);
}

bool same_set(int i , int j){
    return (find_set(i) == find_set(j));
}

void union_set(int i, int j){
    int x = find_set(i), y = find_set(j);
    if(x > y) p[y] = x;
    else p[x] = y;
}

bool dfs(int a , int b) {
    if(a == b)
      return 0;
    vis[a] = 1;
    for (auto i : ans[a]) {
    if(!vis[i.first]) {
        if(dfs(i.first , b)) {
            answ = max(answ, i.second);
            //dfs(i.first, b);
            return true;
        }
      }
    }
     return false;


}

int main(){

    ios::sync_with_stdio(0);

    int a,b,d,cont = 1;
    while(cin >> c >> s >> q && (c || s || q)){
        if(cont != 1) cout << endl;
        vec.clear(); ans.clear(); p.clear(); p.resize(c); ans.resize(c); vis.clear(); vis.resize(c , 0);
        for (int i = 0; i < s; ++i) {
            cin >> a >> b >> d;
            vec.push_back(make_pair(d,make_pair(a - 1 , b - 1)));
        }
        sort(vec.begin(),vec.end());
        union_find();

        for (auto i : vec) {
            if(!same_set(i.second.first , i.second.second))
                ans[i.second.first].push_back(make_pair(i.second.second , i.first)),
                ans[i.second.second].push_back(make_pair(i.second.first , i.first)),
                union_set(i.second.first , i.second.second);
        }
        cout << "Case #"<<cont++<<endl;
        for(int i = 0 ; i < q ; i++){
            cin >> a >> b;
            vis.clear(); vis.resize(c,0);
            a--; b--;
            if(!same_set(a,b)) cout << "no path\n";
            else {
                answ = -1;
                if(dfs(a,b))
                cout << answ << endl;
            }
        }
    }

    return 0;
}

#endif