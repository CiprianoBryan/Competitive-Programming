#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
int a[N];

void solve() {
	int n, b;
	cin >> n >> b;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		if (b >= a[i]) {
			b -= a[i];
			ans ++;
		}
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
