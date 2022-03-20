#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int ans = 2;
	for (int i = 2; i < n; i ++) {
		int len = 2;
		for (; i < n && a[i] - a[i-1] == a[i-1] - a[i-2]; i ++, len ++);
		ans = max(ans, len);
	}
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

