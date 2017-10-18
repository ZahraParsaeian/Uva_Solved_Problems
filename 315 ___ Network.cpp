//In his name
//In his name
//AC

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

vector<int>adj[101];
set<int>ans;
int cont, dfsLow[110], dfsNum[110], vis[110], parent[110], lev, dfsRoot, rootChilds;

void artpnt(int u){
	dfsNum[u] = dfsLow[u] = lev++;  vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (vis[v] == 0){
			parent[v] = u;
			if (u == dfsRoot)    rootChilds++;
			artpnt(v);

			if (dfsLow[v] >= dfsNum[u]){
				if (u == dfsRoot){
					if (rootChilds >= 2)  ans.insert(u);
				}
				else   ans.insert(u);    //why?!
			}
			dfsLow[u] = min(dfsLow[u], dfsLow[v]);
		}
		else if (parent[u] != v)    dfsLow[u] = min(dfsLow[u], dfsNum[v]);
	}
}

int main(){

	ios::sync_with_stdio(0);

	int n;
	string a;
	stringstream str;
	while (cin >> n &&n){
		lev = 0;
		for (int i = 0; i < 101; i++) {
			adj[i].clear();  
			dfsLow[i] = dfsNum[i] = parent[i] = vis[i] = 0;
		}
		//cin.ignore();
		cin.get();
		while (getline(cin, a) && a[0] != '0'){
			str.clear();
			str << a;
			int from, to;
			str >> from;
			while (str >> to){
				adj[from].push_back(to);
				adj[to].push_back(from);
			}
		}
		cont = 0;
		for (int i = 1; i <= n; i++){
			if (!vis[i]){
				rootChilds = 0;
				dfsRoot = i;
				artpnt(i);
			}
		}
		cout << ans.size() << endl;
		ans.clear();
	}
	return 0;
}