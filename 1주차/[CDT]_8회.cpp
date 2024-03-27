// https://www.codetree.ai/missions/2/problems/move-to-max-k-times/description
// 1ȸ�� 40�� ���� �ҿ�
#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

int n, k, r, c;	// r, c���� ��� ��ġ�� ��� ���ŵ� ����
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int grid[101][101];
bool visited[101][101];
queue<pair<int, int>> q;		// ������ ��� ��ġ ���� BFS ������ ť
queue<pair<int, int>> start;	// BFS �����ϸ� �߰��� �ִ��� ĭ ��ǥ ���� ť

bool InRange(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	// ������� �ִ� ������ ū �����δ� �̵��� �� ����
	else if (visited[x][y] || grid[x][y] >= grid[r][c])
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

	cin >> r >> c;
	start.push(make_pair(r, c));
	
	// max_r, max_c���� ���� ��ġ ������ ���� �� �� �ִ��� ĭ�� ��ǥ ����
	int max_r = r;
	int max_c = c;
	
	while (!start.empty() && k > 0) {
		// ���� ĭ���� ���� ���� �� �ִ� ������ ����
		// ���� ĭ �� �̻��� ĭ�� canGo �Լ� ���ο��� �̹� �ɷ���
		int max_val = INT_MIN;
		
		r = start.front().first;
		c = start.front().second;
		start.pop();
		memset(visited, false, sizeof(visited));

		q.push(make_pair(r, c));
		visited[r][c] = true;

		// ��� ��ġ r, c�� ���� BFS ����
		while (!q.empty()) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int new_x = cur_x + dx[i];
				int new_y = cur_y + dy[i];

				if (canGo(new_x, new_y)) {
					// �湮�� ĭ�� ���� �ִ��� ��� ��ǥ Ȯ���Ͽ� ����
					if (grid[new_x][new_y] > max_val) {
						max_val = grid[new_x][new_y];
						max_r = new_x;
						max_c = new_y;
					}
					// �ִ񰪰� ���� ���� �� ��ȣ�� �� ���� �ɷ� ���� 
					else if (grid[new_x][new_y] == max_val) {
						if (new_x < max_r) {
							max_r = new_x;
							max_c = new_y;
						}
						// �� ��ȣ���� ������ �� ��ȣ�� �� ���� �ɷ� ����
						else if (new_x == max_r && new_y < max_c) {
							max_c = new_y;
						}
					}

					visited[new_x][new_y] = true;
					q.push(make_pair(new_x, new_y));
				}
			}
		}

		// ���� ���� ��ġ�� ���� ���� ��ġ�� ���� ��� = �̵��� ���� ����
		if (max_r == r && max_c == c)
			break;
		
		// ���������� ���ŵ� �ִ� ĭ�� ���ο� ���� ��ġ�� ����
		start.push(make_pair(max_r, max_c));
		k--;
	}

	cout << max_r << ' ' << max_c << '\n';

	return 0;
}