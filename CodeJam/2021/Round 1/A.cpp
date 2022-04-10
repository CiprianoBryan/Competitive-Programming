#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 2;
const int INF = 1e9 + 7;

/*********************************/
string num[N];

void addZeros(string &s, int k) {
	while (k --)
		s += '0';
}

int upper(string &numA, string &numB) {
	int szA = numA.size();
	int szB = numB.size();
	if (szA < szB) return 0;
	for (int i = 0; i < szB; i ++) {
		if (numA[i] < numB[i]) {
			addZeros(numB, szA - szB);
			return szA - szB;
		}
		if (numA[i] > numB[i]) {
			addZeros(numB, szA - szB + 1);
			return szA - szB + 1;
		}
	}
	for (int i = szA - 1; i >= szB; i --) {
		if (numA[i] < '9') {
			for (int j = szB; j < i; j ++)
				numB += numA[j];
			numB += numA[i] + 1;
			for (int j = i + 1; j < szA; j ++)
				numB += '0';
			return szA - szB;
		}
	}
	addZeros(numB, szA - szB + 1);
	return szA - szB + 1;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> num[i];
	}
	int ans = 0;
	for (int i = 1; i < n; i ++) {
		ans += upper(num[i-1], num[i]);
//		cout << num[i-1] << " - " <<  num[i] << endl;
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

