//#define Q11995
#ifdef Q11995

//AC

#include<bits/stdc++.h>

using namespace std;

typedef queue<int> qi;
typedef stack<int> si;
typedef priority_queue<int>pqi;
typedef vector<int> vi;

int main(){

    ios::sync_with_stdio(0);

    int n,a,num;
    while(cin>>n) {
        qi q;
        si s;
        pqi p;
        bool cp = true, cq = true, cs = true;
        for (int i = 0; i < n; i++) {
            cin >> num >> a;
            if (num == 1) {
                q.push(a);
                p.push(a);
                s.push(a);
            } else if (num == 2) {
                if (!q.empty() && q.front() == a && cq)
                    q.pop();
                else
                    cq = false;
                if (!s.empty() && s.top() == a && cs)
                    s.pop();
                else
                    cs = false;
                if (!p.empty() && p.top() == a && cp)
                    p.pop();
                else
                    cp = false;
            }
        }
        if ((cp && cs) || (cs && cq) || (cp && cq) || (cp && cs && cq))
            cout << "not sure\n";
        else if (cs)
            cout << "stack\n";
        else if (cp)
            cout << "priority queue\n";
        else if (cq)
            cout << "queue\n";
        else
            cout << "impossible\n";
    }

    return 0;
}

#endif