#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 2;
const int INF = 1e9 + 7;

/*********************************/
int pos[N];

int main() {
	int t;
	cin >> t;
	int n, a;
	while (t --) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			scanf("%d", &a);
			pos[a] = i;
		}
		vector<int> moves(n);
		for (int num = n; num >= 1; num --) {
			moves[num-1] = (pos[num] - (num - 1) + num)%num;
			for (int i = 1; i <= num; i ++) {
				pos[i] = (pos[i] - moves[num-1] + num)%num;
			}
		}
		for (int num = 1; num <= n; num ++) {
			printf("%d ", moves[num-1]);
		}
		cout << endl;
	}

	return 0;
}

