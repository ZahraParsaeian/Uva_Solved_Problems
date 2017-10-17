//#define Q872
#ifdef Q872

//AC

#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<char,char> cc;
typedef vector<string> vs;


int n; vc vec; set<cc> st; vs ts;

void match(string s , int bitmask){
    if ( s.size() == n){
        ts.push_back(s);
        return ;
    }
    for ( int i = 0; i < n; i++){
        if ( bitmask & (1 << i)) continue;
        bool happen = false;
        for ( auto &c : s){
            if ( st.find(make_pair(vec[i],c)) != st.end()){
                happen = true;
                break;
            }
        }
        if ( happen ) continue;
        string ss = s + vec[i];
        match(ss , bitmask | (1 << i));
    }
}

int main(){

    ios::sync_with_stdio(0);

    int tc; cin >> tc;
    string fake; getline(cin , fake);
    while ( tc-- ) {
        st.clear();
        ts.clear();
        vec.clear();
        getline(cin, fake);
        string a;
        char m;
        getline(cin, a);
        stringstream str(a);
        while (str >> m) vec.push_back(m);
        n = vec.size();
        getline(cin, a);
        stringstream str2(a);
        while (str2 >> a) st.insert(make_pair(a[0], a[2]));
        a.clear();
        match(a, 0);
        if (ts.size()) {
            sort(ts.begin(), ts.end());
            for (int i = 0; i < ts.size(); i++) {
                for (int j = 0; j < ts[i].size(); j++) {
                    cout << ts[i][j];
                    if (j != ts[i].size() - 1)
                        cout << " ";
                }
                cout << endl;
            }
        }
        else cout << "NO\n";
        if ( tc ) cout << endl;
    }

    return 0;
}

#endif