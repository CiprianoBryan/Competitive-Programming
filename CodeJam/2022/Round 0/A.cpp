#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
void solve() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < c; i ++) {
		if (i == 0) cout << "..";
		if (i == 1) cout << "+";
		if (i >= 1) cout << "-+";
		if (i == c - 1) cout << endl;
	}
	for (int i = 0; i < r; i ++) {
		for (int k = 0; k < 2; k ++) {
			for (int j = 0; j < c; j ++) {
				if (k == 0 && i == 0 && j == 0) cout << ".";
				if (k == 0 && i != 0 && j == 0) cout << "|";
				if (k == 0) cout << ".|";
				if (k == 1 && j == 0) cout << "+";
				if (k == 1) cout << "-+";
				if (j == c - 1) cout << endl;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int nroCase = 1; nroCase <= t; nroCase ++) {
		cout << "Case #" << nroCase << ":\n";
		solve();
	}
	
	return 0;
}

