#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
int dp[51][50*30+1];

void solve() {
	int n, k, p;
	cin >> n >> k >> p;
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1, sum = 0; j <= k; j ++) {
			int plate;
			cin >> plate;
			sum += plate;
			for (int have = 0; have + j <= p; have ++) {
				dp[i][have+j] = max(dp[i][have+j], dp[i-1][have+j]);
				dp[i][have+j] = max(dp[i][have+j], sum + dp[i-1][have]);
			}
		}
	}
	cout << dp[n][p] << endl;
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

