#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 2;
const int INF = 1e9 + 7;
const int LEN = 6;

/*********************************/
bool memo[N][1 << LEN];
bool used[N][1 << LEN];
int dig[LEN];
int n;
string s;

int build(int mask, int newDig) {
	if (mask&(1 << (LEN - 1)))
		return ((mask^(1 << (LEN - 1))) << 1)|newDig;
	return (mask << 1)|newDig;
}

bool isPal(int mask, int pos) {
	if (pos < 5) return false;
	for (int i = 0; i < LEN; i ++, mask >>= 1) {
		dig[i] = (mask&1);
	}
	bool find = false;
	find |= (dig[0] == dig[4] && dig[1] == dig[3]);
	if (pos > 5) {
		find |= (dig[1] == dig[5] && dig[2] == dig[4]);
		find |= (dig[0] == dig[5] && dig[1] == dig[4] && dig[2] == dig[3]);
	}
	return find;
}

bool dp(int pos, int mask) {
	if (pos == n) return !isPal(mask, pos);
	if (isPal(mask, pos)) return false;
	if (used[pos][mask]) return memo[pos][mask];
	used[pos][mask] = true;
	bool &ans = memo[pos][mask] = false;
	if (s[pos] != '?') {
		ans |= dp(pos + 1, build(mask, s[pos] - '0'));
	} else {
		ans |= dp(pos + 1, build(mask, 0));
		ans |= dp(pos + 1, build(mask, 1));
	}
	return ans;
}

void solve() {
	memset(used, 0, sizeof used);
	cin >> n >> s;
	if (dp(0, 0)) {
		cout << "POSSIBLE\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
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

