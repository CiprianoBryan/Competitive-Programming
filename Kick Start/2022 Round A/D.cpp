#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
long long memo[14][110][110][2];
int used[14][110][110][2];
int sumExpected;

long long dp(vector<int> &num, int sum, int pos, int multp, bool isLess, bool leadingZeros = true) {
	if (pos == num.size()) {
		return (multp == 0 && sum == 0);
	}
	if (used[pos][sum][multp][isLess]) return memo[pos][sum][multp][isLess];
	used[pos][sum][multp][isLess] = true;
	long long &ans = memo[pos][sum][multp][isLess] = 0LL;
	for (int dig = 0; dig <= 9; dig ++) {
		if (!isLess && dig > num[pos]) continue;
		if (sum < dig) continue;
		bool newLeadingZeros = dig != 0? false: leadingZeros;
		int newMultp = newLeadingZeros? multp: (multp*dig)%sumExpected;
		ans += dp(num, sum - dig, pos + 1, newMultp, isLess|(dig < num[pos]), newLeadingZeros);
	}
	return ans;
}

vector<int> build(long long num) {
	vector<int> s;
	while (num) {
		s.push_back(num%10);
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

void solve() {
	long long a, b;
	cin >> a >> b;
	vector<int> numB = build(b);
	vector<int> numA = build(a - 1);
	long long countB = 0;
	sumExpected = 1;
	for (; sumExpected <= 108; sumExpected ++) {
		memset(used, 0, sizeof used);
		countB += dp(numB, sumExpected, 0, 1, false);
	}
	long long countA = 0;
	sumExpected = 1;
	for (; sumExpected <= 108; sumExpected ++) {
		memset(used, 0, sizeof used);
		countA += dp(numA, sumExpected, 0, 1, false);
	}
	cout << countB - countA << endl;
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

