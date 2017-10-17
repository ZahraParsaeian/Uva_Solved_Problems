//#define Q1056
#ifdef Q1056

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define inf 1e9

int main(){

    ios::sync_with_stdio(0);
    int p , r;
    int tc = 1;
    while( cin >> p >> r && (r || p)){
        map < string , int > m;
        string a , b;
        int cont  = 0;
        vvi vec(p, vi(p , inf));
        for ( int i = 0 ; i < r ; i++){
            cin >> a >> b;
            if (!m.count(a))
                m[a] = cont++;
            if(!m.count(b))
                m[b] = cont++;
            vec[m[a]][m[b]] = 1;
            vec[m[b]][m[a]] = 1;
        }
        for (int l = 0; l < p; ++l) {
            vec[l][l] = 0;
        }
        for (int k = 0; k < p; k++)
            for(int i = 0; i < p; i++)
                for (int j = 0; j < p; ++j)
                    vec[i][j] = min (vec[i][j] , vec[i][k] + vec[k][j]);
        int mx = -1;
        for (int i = 0; i < p; i++)
            for ( int j = 0; j < p; j++)
                mx = max (mx , vec[i][j]);
        cout << "Network "<<tc++<<": ";
        if(mx != inf)  cout<<mx;
        else  cout << "DISCONNECTED";
        cout << endl << endl;
    }

    return 0;
}

#endif