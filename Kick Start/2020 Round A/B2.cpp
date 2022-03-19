#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
int dp[2][50*30+1];

void solve() {
	int n, k, p;
	cin >> n >> k >> p;
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i ++) {
		memcpy(dp[0], dp[1], sizeof dp[0]);
		for (int j = 1, sum = 0; j <= k; j ++) {
			int plate;
			cin >> plate;
			sum += plate;
			for (int have = 0; have + j <= p; have ++) {
				dp[1][have+j] = max(dp[1][have+j], sum + dp[0][have]);
			}
		}
	}
	cout << dp[1][p] << endl;
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

