#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/

int main() {
	int t;
	cin >> t;
	int l, r, a;
	while (t --) {
		cin >> l >> r >> a;
		int k = (r+1)/a;
		int ans = r/a + (r%a);
		if (l <= a*k - 1) {
			ans = k + a - 2;
		}
		cout << ans << endl;
	}

	return 0;
}

