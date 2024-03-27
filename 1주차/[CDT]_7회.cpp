// https://www.codetree.ai/missions/2/problems/places-can-go/description
#include <iostream>
#include <queue>
using namespace std;

int n, k, cnt;	// cnt : �湮 ������ ĭ ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int grid[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

// ������� 1-based �����̶� range check�� 1-based ������� ����
bool InRange(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	// �湮 ������ ������ 1�� �ƴ϶� 0��
	else if (visited[x][y] || grid[x][y] == 1)
		return false;
	else
		return true;
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> grid[i][j];
		}
	}

	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;

		// �̹� ������� �湮�� ��� �ش� ��ġ���� BFS �������� ����
		if (visited[x][y])
			continue;

		visited[x][y] = true;
		q.push(make_pair(x, y));

		while (!q.empty()) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			cnt++;	// �湮 ������ ���� +1 �߰�
			q.pop();

			for (int i = 0; i < 4; i++) {
				int new_x = cur_x + dx[i];
				int new_y = cur_y + dy[i];

				if (canGo(new_x, new_y)) {
					visited[new_x][new_y] = true;
					q.push(make_pair(new_x, new_y));
				}
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}