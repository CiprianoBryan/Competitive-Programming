#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 2;
const int INF = 1e9 + 7;

/*********************************/
int trie[N][26];
int freq[N];
int n, k;
int ans;

void dfs(int node = 0, int len = 0) {
	for (int i = 0; i < 26; i ++) {
		if (trie[node][i]) {
			dfs(trie[node][i], len + 1);
			freq[node] += freq[trie[node][i]];
		}
	}
	if (freq[node] >= k) {
		ans += freq[node]/k*len;
		freq[node] -= freq[node]/k*k;
	}
}

void solve() {
	memset(trie, 0, sizeof trie);
	memset(freq, 0, sizeof freq);
	cin >> n >> k;
	string s;
	int sizeTrie = 1;
	while (n--) {
		cin >> s;
		int node = 0;
		for (char &c: s) {
			if (!trie[node][c-'A'])
				trie[node][c-'A'] = sizeTrie ++;
			node = trie[node][c-'A'];
		}
		freq[node] ++;
	}
	ans = 0;
	dfs();
	cout << ans << endl;
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

