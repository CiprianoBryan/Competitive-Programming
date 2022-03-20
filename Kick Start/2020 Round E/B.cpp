#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int x = a - c;
	int y = b - c;
	if ((x + c + y > n) || (x == 0 && y == 0 && c == 1 && n > 1)) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	if (x == 0 && y == 0) {
		cout << n << " ";
		for (int i = 0; i < n - c; i ++)
			cout << n - 1 << " ";
		for (int i = 0; i < c - 1; i ++)
			cout << n << " ";
	} else {
		for (int i = 0; i < x; i ++)
			cout << n - 1 << " ";
		if (x > 0)
			for (int i = 0; i < n - (x + c + y); i ++)
				cout << n - 2 << " ";
		for (int i = 0; i < c; i ++)
			cout << n << " ";
		if (x == 0 && y != 0)
			for (int i = 0; i < n - (x + c + y); i ++)
				cout << n - 2 << " ";
		for (int i = 0; i < y; i ++)
			cout << n - 1 << " ";
	}
	cout << endl;
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

