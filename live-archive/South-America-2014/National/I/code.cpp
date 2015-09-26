#include <bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define MAX 2000000
#define pb push_back
using namespace std;

vector< pii > g[MAX];
bool f[MAX];
int w = 0, ret = 0;

void dfs(int u, int fri, int dep) {
	int v,ff = 0, cost;
	fri = f[u];
	if (f[u]) ret = max(ret,dep);
	for (int i = 0; i < g[u].size(); i++) {
		v = g[u][i].F;
		dfs(v,false, dep + g[u][i].S);
		if (ff > 0) {
			w += g[u][i].second;
			friends += ff;
		}
	}
}

int main() {

	int n, m;
	int x, y, z;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++)
			g[i].clear(), f[i] = 0;

		for (int i = 1; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			g[x].push_back(make_pair(y, z));
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			f[x] = 1;
		}

		w = 0, ret = 0;
		dfs(1, false, 0);
		sort(ans.begin(),ans.end());
		for(int i = 0; i < ans.size()-1; i++)
			res += ans[i];		
		printf("%d\n", res);
	}
	return 0;
}