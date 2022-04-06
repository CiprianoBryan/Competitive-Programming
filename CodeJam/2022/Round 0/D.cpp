#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
vector<int> adj[N];
int f[N];

pair<long long, int> dfs(int node) {
	if (adj[node].empty())
		return {0, f[node]};
	long long sum = 0;
	int less = INF;
	for (int &child: adj[node]) {
		pair<long long, int> resp = dfs(child);
		sum += resp.first;
		if (resp.second < less) {
			sum += less == INF? 0: less;
			less = resp.second;
		} else {
			sum += resp.second;
		}
	}
	return {sum, max(less, f[node])};
}

void solve() {
	int n, p;
	cin >> n;
	adj[0].clear();
	for (int i = 1; i <= n; i ++) {
		cin >> f[i];
		adj[i].clear();
	}
	for (int i = 1; i <= n; i ++) {
		cin >> p;
		adj[p].push_back(i);
	}
	pair<long long, int> ans = dfs(0);
	cout << ans.first + ans.second << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int nroCase = 1; nroCase <= t; nroCase ++) {
		cout << "Case #" << nroCase << ": ";
		solve();
	}
	
	return 0;
}

