//In his name
//AC

#include<iostream>
#include<sstream>
#include<string>
#include<string.h>

using namespace std;

int vis[101][101], d1[] = {-1,0,1,-1,1,-1,0,1}, d2[] = {-1,1,-1,0,0,1,-1,1},n;
string a[101];
int dfs(int u, int v){
	if (u < 0 || u >= n || v < 0 || v >= a[0].length())  return 0;
	if (vis[u][v] || a[u][v] != 'W')   return 0;
	vis[u][v] = 1;
	int ans=1;
	for (int i = 0; i < 8; i++){
		ans += dfs(u + d1[i], v + d2[i]);
	}
	return ans;
}

int main(){

	ios::sync_with_stdio(0);

	int tc,u,v;
	string b;
	cin >> tc;   cin.ignore();   cin.ignore();
	while (tc--){
		memset(vis, 0, sizeof vis);
		n = 0;
		while (getline(cin,b) && (b[0] == 'W' || b[0] == 'L'))   a[n] = b, n++;
		stringstream str;
		while (b.length() > 0){
			str.clear();
			str << b; str >> u;  str >> v;
			memset(vis, 0, sizeof vis);
			u--; v--;
			cout << dfs(u, v)<<endl;	
			getline(cin, b);
		}
		if (tc != 0)  cout << endl;
	}
	return 0;
}