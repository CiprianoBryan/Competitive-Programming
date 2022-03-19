#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
inline isEven(int num) {
	return !(num&1);
}

int main() {
	int t;
	cin >> t;
	string s;
	char c;
	while (t --) {
		cin >> s >> c;
		bool poss = false;
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == c && (isEven(i) && isEven(s.size() - 1 - i))) {
				poss = true;
				break;
			}
		}
		cout << (poss? "YES\n": "NO\n");
	}
	
	return 0;
}

