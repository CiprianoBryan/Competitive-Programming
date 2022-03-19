#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
int a[51][31];
int sums[51][31];
int n, k, p;

int used[51][50*30+1];
int memo[51][50*30+1];

int dp(int pos, int p) {
	if (pos > n) return 0;
	if (p == 0) return 0;
	if (used[pos][p]) return memo[pos][p];
	used[pos][p] = true;
	int &ans = memo[pos][p] = 0;
	for (int i = 0; i <= min(k, p); i ++) {
		ans = max(ans, sums[pos][i] + dp(pos + 1, p - i));
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	for (int nroCase = 1; nroCase <= t; nroCase ++) {
		cin >> n >> k >> p;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= k; j ++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= k; j ++) {
				sums[i][j] = a[i][j] + sums[i][j-1];
			}
		}
		memset(used, 0, sizeof used);
		printf("Case #%d: %d\n", nroCase, dp(1, p));
	}

	return 0;
}

