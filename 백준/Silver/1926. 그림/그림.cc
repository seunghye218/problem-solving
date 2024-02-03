#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m));
	for (int i = 0 ; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> paper[i][j];
		}
	}
	
	static int dx[4] = {0, 1, 0, -1};
	static int dy[4] = {1, 0, -1, 0};
	vector<int> draws;

	queue<pair<int, int>> Q;
	for (int i = 0 ; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (paper[i][j]) {
				draws.push_back(1);
				Q.push({j, i});
				paper[i][j] = 0;
				while (!Q.empty()) {
					auto [x, y] = Q.front();
					Q.pop();
					for (int k = 0; k < 4; ++k) {
						int x2 = x + dx[k];
						int y2 = y + dy[k];
						if (x2 >= 0 && y2 >= 0 && x2 < m && y2 < n && paper[y2][x2]) {
							paper[y2][x2] = 0;
							Q.push({x2, y2});
							++draws.back();
						}
					}
				}
			}
		}
	}
	cout << draws.size() << '\n' << (!draws.size() ? 0 : *max_element(draws.begin(), draws.end()));
}