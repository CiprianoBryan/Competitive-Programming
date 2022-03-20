#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e9 + 7;

/*********************************/
void solve() {
	string num;
	cin >> num;
	int sumDig = 0;
	for (char &d: num) {
		sumDig += d - '0';
	}
	int add = 0;
	for (; add <= 9; add ++) 
		if ((sumDig + add + 9)%9 == 0) 
			break;
	if (add == 0) {
		cout << num[0] << "0";
		if (num.size() > 1)
			cout << num.substr(1);
		cout << endl;
		return;
	}
	for (int i = 0; i <= num.size(); i ++) {
		if (i == num.size() || add < num[i]-'0') {
			cout << num.substr(0, i) << add;
			if (i != num.size())
				cout << num.substr(i);
			cout << endl;
			return;
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
		cout << "Case #" << nroCase << ": ";
		solve();
	}
	
	return 0;
}

