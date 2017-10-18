#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
 
//AC

using namespace std;

//#define INF 1000000
#define INF (int)1e9
int adj[101][101];

int main(){

	ios::sync_with_stdio(0);

	int tc,cont=1,ver,edge,u,v;
	cin >> tc;
	while (tc--){
		for (int i = 0; i < 101; i++){
			for (int j = 0; j < 101; j++)
			if (i != j)
				adj[i][j] = INF;
			else
				adj[i][j] = 0;
		}
		cin >> ver >> edge;
		for (int i = 0; i < edge; i++){
			cin >> u >> v;
				adj[u][v] = 1, adj[v][u] = 1;
		}
		for (int k = 0; k < ver; k++){
			for (int i = 0; i < ver; i++){
				for (int j = 0; j < ver; j++){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		int s, d;
		cin >> s >> d;
		int ans = 0;
		for (int i = 0; i < ver; i++){
			if (adj[s][i] != INF&&adj[i][d] != INF)
				ans = max(ans, adj[s][i] + adj[i][d]);
		}
		cout <<"Case "<<cont<<": " <<ans << endl;
		cont++;
	}

	return 0;
}