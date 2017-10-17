//#define Q10507
#ifdef Q10507

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {

    ios::sync_with_stdio(0);

    int n, m;
    while (cin >> n >> m) {
        int awake = 3;
        map<int, bool> mp;
        vi vis(26);
        vvi vec(26);
        char a;
        for (int i = 0; i < 3; i++) {
            cin >> a;
            vis[a - 65] = 1;
        }
        char s, d;
        for (int i = 0; i < m; i++) {
            cin >> s >> d;
            vec[s - 65].push_back(d - 65);
            vec[d - 65].push_back(s - 65);
        }
        bool check = false;
        int year = 0;
        for (year; year < n; year++) {
            vi tmpvis(26,0);
            if(count(vis.begin(),vis.end(),1)==n){
                check=true;
                break;
            }
            for (int i = 0; i < 26; i++) {
                if(!vis[i]) {
                    int mm = 0;
                    for (int j = 0; j < vec[i].size(); j++) {
                        if (vis[vec[i][j]]) {
                            mm++;
                        }

                    }
                    if (mm >= 3) {
                        tmpvis[i]=1;
                    }
                }
            }
            for(int i=0;i<26;i++)
                if(tmpvis[i])  vis[i]=1;

        }
        if (!check)
            cout << "THIS BRAIN NEVER WAKES UP\n";
        else {
            cout << "WAKE UP IN, " << year<< ", YEARS" << endl;
        }
    }

    return 0;
}

#endif