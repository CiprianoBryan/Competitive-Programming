#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/

int main() {
	int t;
	cin >> t;
	int n, m;
	int x, w;
	while (t --) {
		cin >> n >> m;
		vector<vector<int>> points;
		for (int i = 0; i < m; i ++) {
			cin >> x >> w;
			points.push_back({x, w, i});
		}
		sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
			return a[1] < b[1];
		});
		int sumWeight = 0;
		vector<Pair> positions;
		for (int i = 0; i < 2*n; i ++) {
			sumWeight += points[i][1];
			positions.push_back({points[i][0], points[i][2] + 1});
		}
		sort(positions.begin(), positions.end());
		cout << sumWeight << endl;
		for (int i = 0; i < n; i ++) {
			printf("%d %d\n", positions[i].second, positions[2*n - 1 - i].second);
		}
		cout << endl;
	}

	return 0;
}

