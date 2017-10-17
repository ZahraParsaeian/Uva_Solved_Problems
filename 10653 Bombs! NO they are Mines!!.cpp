//#define Q10653
#ifdef Q10653

//AC

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main(){

    ios::sync_with_stdio(0);

    int c,r;
    while( cin >> r >> c && (r || c)){
        vector<vector<int>> vec(r,vector<int>(c , -10));
        int n,row,num,col; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> row >> num;
            for (int j = 0; j < num; ++j) {
                cin >> col;
                vec[row][col] = -1;
            }
        }
        cin >> row >> col;
        vec[row][col] = 0;
        queue<pair<int,int>> q;
        q.push(make_pair(row , col));
        cin >> row >> col;
        bool check = true;
        while(check){
            ii a = q.front(); q.pop();
            if(a.first - 1 >= 0 && a.first - 1 < r && a.second >=0 && a.second < c) {
                if (vec[a.first - 1][a.second] != -1 && vec[a.first - 1][a.second] == -10) {
                    vec[a.first - 1][a.second] = vec[a.first][a.second] + 1;
                    q.push(make_pair(a.first - 1, a.second));
                    if ((a.first - 1) == row && a.second == col) {
                        check = false;
                        break;
                    }
                }
            }
            if(a.first + 1 >= 0 && a.first + 1 < r && a.second >=0 && a.second < c) {
                if (vec[a.first + 1][a.second] != -1 && vec[a.first + 1][a.second] == -10) {
                    vec[a.first + 1][a.second] = vec[a.first][a.second] + 1;
                    q.push(make_pair(a.first + 1, a.second));
                    if ((a.first + 1) == row && a.second == col) {
                        check = false;
                        break;
                    }
                }
            }
            if(a.first  >= 0 && a.first  < r && a.second - 1 >=0 && a.second - 1 < c) {
                if (vec[a.first][a.second - 1] != -1 && vec[a.first][a.second - 1] == -10) {
                    vec[a.first][a.second - 1] = vec[a.first][a.second] + 1;
                    q.push(make_pair(a.first, a.second - 1));
                    if (a.first == row && (a.second - 1) == col) {
                        check = false;
                        break;
                    }
                }
            }
            if(a.first >= 0 && a.first < r && a.second + 1 >=0 && a.second + 1 < c) {
                if (vec[a.first][a.second + 1] != -1 && vec[a.first][a.second + 1] == -10) {
                    vec[a.first][a.second + 1] = vec[a.first][a.second] + 1;
                    q.push(make_pair(a.first, a.second + 1));
                    if (a.first == row && (a.second + 1) == col) {
                        check = false;
                        break;
                    }
                }
            }
        }
        cout << vec[row][col] << endl;
    }

    return 0;
}

#endif