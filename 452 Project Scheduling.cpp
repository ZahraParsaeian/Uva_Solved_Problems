//#define Q452
#ifdef Q452

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

int main() {

    ios::sync_with_stdio(0);

    int tc;
    cin >> tc;
    string a, chrt;
    getline(cin, chrt);
    getline(cin, chrt);
    while (tc--) {
        vi time(27);
        vvi vec(27);
        vi alph(27, 0);
        while (getline(cin, a) && a.length()) {
            char b;
            int num;
            stringstream str(a);
            str >> b;
            str >> num;
            time[b - 'A'] = num;
            alph[b - 'A']++;
            string c;
            str >> c;
            for (auto i : c)
                vec[b - 'A'].push_back(i - 'A'), alph[i - 'A']++;
        }
        qi q;
        int mx = -inf;
        vi dist(27, -inf);
        for (int i = 0; i < 27; ++i)
            if (alph[i])
                q.push(i), dist[i] = time[i], mx = max(mx, time[i]);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto i : vec[u]) {
                if (dist[i] < dist[u] + time[i]) {
                    dist[i] = dist[u] + time[i];
                    mx = max(mx, dist[i]);
                    q.push(i);
                }
            }
        }
        cout << mx << endl;
        if (tc)
            cout << endl;
    }

    return 0;
}

#endif