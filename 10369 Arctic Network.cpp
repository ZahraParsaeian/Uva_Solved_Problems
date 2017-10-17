//#define Q10369
#ifdef Q10369

//AC

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii vec;
vector<pair<double,ii>> v;
vi p;
vector<double> ans;
int s,pp;

void union_find(){
    for (int i = 0; i < pp; ++i)
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

int main(){

    ios::sync_with_stdio(0);

    int tc , x , y;  cin >> tc;
    while(tc--){
        cin >> s >> pp;
        vec.clear(); v.clear(); p.clear(); p.resize(pp); ans.clear();
        vii a;
        for (int i = 0; i < pp; ++i) {
            cin >> x >> y;
            vec.push_back(make_pair(x,y));
        }
        for (int j = 0; j < pp; ++j) {
            for (int i = 0; i < pp; ++i) {
                double b = hypot(vec[j].first - vec[i].first , vec[j].second - vec[i].second);
                v.push_back(make_pair(b,make_pair(j , i)));
            }
        }
        sort(v.begin(), v.end());
        union_find();
        for (int i = 0; i < v.size(); i++) {
            if(!same_set(v[i].second.first , v[i].second.second)){
                ans.push_back(v[i].first);
                union_set(v[i].second.first , v[i].second.second);
            }
        }
        sort(ans.rbegin() , ans.rend());
        cout << fixed << setprecision(2) << ans[s - 1] << endl;
    }


    return 0;
}

#endif