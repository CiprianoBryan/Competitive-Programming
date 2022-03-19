#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
int m[N];
int n, k;

bool ok(int diff) {
	int count = 0;
	for (int i = 1; i < n; i ++) {
		count += (m[i]-m[i-1]-1)/diff;
	}
	return count <= k;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i ++) {
		cin >> m[i];
	}
	int left = 1, right = m[n-1] - m[0];
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (ok(mid)) right = mid - 1;
		else left = mid + 1;
	}
	cout << left << endl;
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

