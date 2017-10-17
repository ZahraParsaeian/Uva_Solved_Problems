//#define Q314
#ifdef Q314

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;


int n,m , row1 , row2 , col1 , col2;
string aa;
vvi vec;
map<string, int > mp;
vector<vector<vector<int>>> vis;

int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};

struct nod {
    int x, y , dir , time;
    nod(int a , int b , int c , int d) {
        x = a; y = b; dir = c; time = d;
    }
};

bool check(int a , int b) {
    if(a<=0 || b<=0 || a>=m || b>=n) return false;
    if(vec[a-1][b-1]) return false;
    if(vec[a-1][b]) return false;
    if(vec[a][b-1]) return false;
    if(vec[a][b]) return false;

    return true;
}

int get_ans(){
    cin >> row1 >> col1 >> row2 >> col2 >> aa;
    queue<nod> q;
    if(check(row1 , col1)){
        int d = mp[aa];
        q.push(nod(row1 , col1 , d, 0));
        vis[row1][col1][d] = 1;
    }
    while(!q.empty()){
        nod b = q.front(); q.pop();

        if(b.x == row2 && b.y == col2) return b.time;

        if(!vis[b.x][b.y][(b.dir + 1)%4]) {
            vis[b.x][b.y][(b.dir + 1) % 4] = 1;
            q.push(nod(b.x, b.y, (b.dir + 1) % 4, b.time + 1));
        }

        if(!vis[b.x][b.y][(b.dir + 3)%4]) {
            vis[b.x][b.y][(b.dir + 3) % 4] = 1;
            q.push(nod(b.x, b.y, (b.dir + 3) % 4, b.time + 1));
        }
        for(int i = 1 ; i <= 3 ; i++){
            if(check(b.x + di[b.dir] * i , b.y + dj[b.dir] * i)){
                if(!vis[b.x + di[b.dir] * i][b.y + dj[b.dir] * i][b.dir]){
                    vis[b.x + di[b.dir] * i][b.y + dj[b.dir] * i][b.dir] = 1;
                    q.push(nod(b.x + di[b.dir] * i , b.y + dj[b.dir] * i, b.dir , b.time + 1));
                }
            }
            else break;
        }

    }
    return -1;
}

int main() {

    ios::sync_with_stdio(0);

    mp["south"] = 2;
    mp["north"] = 0;
    mp["east"] = 1;
    mp["west"] = 3;

    while (cin >> m >> n && (n || m)) {
        vec.clear();
        vec.resize(m, vi(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> vec[i][j];
            }
        }
        vis.clear(); vis.resize(m, vvi(n  , vi (4 , 0)));
        cout << get_ans() << endl;

    }


    return 0;

}


#endif