#define Qdfs
#ifdef Qdfs

//AC

#include<iostream>
#include<vector>
#include<string.h>
#include<stack>

using namespace std;

vector<int>adj[201];
int color[201], vis[201];

bool dfs(int d){
	stack<int>s;
	s.push(d);
	while (!s.empty()){
		int u = s.top();
		s.pop();
		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			if (color[v] == -1){
				color[v] = 1 - color[u];
				s.push(v);
			}
			else if (color[v] == color[u])   return false;
		}
	}
	return true;
}

int main(){

	ios::sync_with_stdio(0);

	int n, l, x, y;
	while (cin >> n && n){
		memset(color, -1, sizeof color);
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < 201; i++)  adj[i].clear();
		cin >> l;
		for (int i = 0; i < l; i++){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		color[adj[0][0]] = 0;
		if (dfs(adj[0][0]))
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";
	}
	return 0;
}

#endif