//In his name
//AC

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

vector<int>adj[101],ts;
int vis[101];

void dfs(int u){
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (!vis[v])
			dfs(v);
	}
	ts.push_back(u);
}

int main(){

	ios::sync_with_stdio(0);

	int n, m,x,y;
	while (cin >> n >> m){
		if (n == 0 && m == 0)  break;
		ts.clear();
		for (int i = 0; i < 101; i++)  adj[i].clear();
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < m; i++){
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= n; i++){
			if (!vis[i])
				dfs(i);
		}
		for (int i = ts.size() - 1; i >= 0; i--)
			cout << ts[i] << " ";
		cout << endl;	
	}
	return 0;
}