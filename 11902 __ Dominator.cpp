//In his name
//AC

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string.h>

using namespace std;

vector<int>adj[101];int vis[101], n, tmpvis[101];

void dfs(int u,int vi[]){
	if (vi[u] != 0)  return;
	vi[u] = 1;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (!vi[v])
			dfs(v,vi);
	}
}

void print(){
	cout << "+";
	for (int i = 0; i < 2 * n - 1; i++)
		cout << "-";
	cout << "+\n";
}

void ans(){
	cout << "|";
	for (int i = 0; i < n; i++){
		cout << ((vis[i] == 1 && (tmpvis[i] == 0 || tmpvis[i] == 2)) ? "Y" : "N") << "|";
	}
	cout << endl;
}

int main(){

	ios::sync_with_stdio(0);

	int tc, num, cont = 1;
	cin >> tc;
	while (tc--){
		for (int i = 0; i < 101; i++)adj[i].clear(), vis[i] = 0;
		cin >> n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> num;
				if (num) adj[i].push_back(j);
			}
		}
		dfs(0, vis);
		cout << "Case " << cont << ":\n";  print();
		for (int i = 0; i < n; i++){
			memset(tmpvis, 0, sizeof tmpvis);
			tmpvis[i] = 2;  dfs(0, tmpvis);
			ans();
			print();
		}
		cont++;
	}
	return 0;
}