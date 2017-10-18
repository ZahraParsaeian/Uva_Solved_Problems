//In his name
//AC

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> adj[27];
int vis[27];

void dfs(int u){
	//if (vis[u])   return;
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (!vis[v])
			dfs(v);
	}
}

int main(){

	ios::sync_with_stdio(0);

	int tc,cont,cc=0;
	char b;
	string a;
	cin >> tc;
	while (tc--){
		cont = 0;
		if (cc != 0)
			cout << endl;
		for (int i = 0; i < 27; i++){
			adj[i].clear();
			vis[i] = 0;
		}
		cin >> b;
		cin.ignore();
		while (getline(cin,a)&&a.length() != 0){
			adj[a[0] - 65].push_back(a[1] - 65);
			adj[a[1] - 65].push_back(a[0] - 65);
		}
		for (int i = 0; i <b-64; i++){
			if (!vis[i]){
				dfs(i);
				cont++;
			}
		}
		cout << cont << endl;
		cc++;
	}
	return 0;
}