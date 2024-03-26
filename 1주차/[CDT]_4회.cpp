// https://www.codetree.ai/missions/2/problems/comfort-zone/description
#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

int n, m, k;
int max_region;
int max_val = INT_MIN;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int town[51][51];
bool visited[51][51];
vector<int> safe_region;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (town[x][y] <= k || visited[x][y])
		return false;
	else
		return true;
}

void dfs(int cur_x, int cur_y) {
	visited[cur_x][cur_y] = true;

	for (int i = 0; i < 4; i++) {
		int new_x = cur_x + dx[i];
		int new_y = cur_y + dy[i];

		if (canGo(new_x, new_y)) {
			dfs(new_x, new_y);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> town[i][j];
		}
	}

	for (k = 1; k <= 100; k++) {
		int cnt = 0;
		// visited 2���� �迭 �ʱ�ȭ (cstring �ʿ�)
		memset(visited, false, sizeof(visited));

		// DFS ���� ���� ��쵵 Ž���ϴ� ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// ���ο� ������ �� �� ���� ���̿� �湮 ���� üũ �ʿ�
				// dfs�� �����ϰ� ��ġ��, dfs ���� ���� ��ŭ�� �ϳ��� �׷�(cnt)�� ��
				if (town[i][j] > k && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		safe_region.push_back(cnt);
	}

	for (int i = 0; i < safe_region.size(); i++) {
		if (safe_region[i] > max_val) {
			max_region = i + 1;
			max_val = safe_region[i];
		}
	}

	cout << max_region << ' ' << max_val << '\n';
	return 0;
}