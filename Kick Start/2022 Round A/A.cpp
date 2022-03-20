#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
int cant1[52];
int cant2[52];

void solve() {
	memset(cant1, 0, sizeof cant1);
	memset(cant2, 0, sizeof cant2);
	string s1, s2;
	cin >> s1 >> s2;
	int ans = 0;
	int it1 = 0, it2 = 0;
	for (; it1 < s1.size() && it2 < s2.size(); it1 ++, it2 ++) {
		for (; it2 < s2.size() && s1[it1] != s2[it2] ; it2 ++) {
			ans ++;
		}
		if (it2 == s2.size())
			break;
	}
	ans += s2.size() - it2;
	if (it1 != s1.size()) cout << "IMPOSSIBLE\n";
	else cout << ans << endl;
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

