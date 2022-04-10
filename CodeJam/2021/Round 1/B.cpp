#include <bits/stdc++.h>
using namespace std;

const int N = 95 + 2;
const int INF = 1e9 + 7;
const long long MAX_COUNT = 1e15;
const int MAX_PRIME = 499;
const int MAX_LEN_CARDS = log2(MAX_PRIME*MAX_COUNT) + 1; //60
const int MAX_SUM_CARDS = MAX_LEN_CARDS*MAX_PRIME + 1; //29940 = 3*10^4

/*********************************/
int p[N];
long long k[N];

bool isPossible(long long product, long long productSum, int n) {
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < k[i] && product%p[i] == 0; j ++) {
			productSum -= p[i];
			product /= p[i];
		}
	}
	return product == 1 && productSum == 0;
}

void solve() {
	int n;
	cin >> n;
	long long totalSum = 0;
	for (int i = 0; i < n; i ++) {
		cin >> p[i] >> k[i];
		totalSum += p[i]*k[i];
	}
	long long ans = 0;
	for (int sum = 2; sum < min(totalSum, 1LL*MAX_SUM_CARDS); sum ++) {
		// sum: suma de cartas que conforman el producto
		// totalSum - sum: suma de cartas que conforman la suma
		if (isPossible(totalSum - sum, sum, n)) {
			ans = totalSum - sum;
			break;
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

