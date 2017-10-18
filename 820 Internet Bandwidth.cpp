#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include<string.h>
#include<map>

//AC

using namespace std;
#define INF 1000000

int res[101][101], mf, f, s, t;
vector<int> p,adj[101];

void augment(int v, int minEdge){
	if (v == s)
	{
		f = minEdge;
		//return;
	}
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int main(){
	ios::sync_with_stdio(0);
	int c, n, a, b, cap,count=1;
	while (cin >> n && n){
		for (int i = 0; i < 101; i++)   adj[i].clear();
		memset(res, 0, sizeof res);
		//p.clear();
		cin >> s >> t >> c;
		s--;  t--;
		while (c--){
			cin >> a >> b >> cap;
			a--; b--;
			res[a][b] += cap;
				res[b][a] += cap;
			adj[a].push_back(b);   adj[b].push_back(a);
		}
		mf = 0;
		while (1){
			f = 0;
			vector<int>dist(n, INF);
			dist[s] = 0;
			queue<int>q;
			q.push(s);
			p.assign(n, -1);
			while (!q.empty()){
				int u = q.front(); q.pop();
				if (u == t)
					break;
				for (int i = 0; i < adj[u].size(); i++){
					int v = adj[u][i];
					if (res[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
				}
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;

		}
		cout << "Network " << count++ << endl
			<< "The bandwidth is " << mf <<".\n"<< endl;

	}



	return 0;
}