// https://www.codetree.ai/missions/2/problems/seperate-village/description
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[26][26];

vector<int> town_size;

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (grid[x][y] == 0 || visited[x][y])
		return false;
	else
		return true;
}

void swap(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

//	<�Ķ���� cnt�� �����ڷ� �Ѱ��ִ� ����>
//	����Լ� ���ο��� ���� ���� ���� ���� �ÿ� ��� ������ ���� ����ȴ�.
//	�����ڷ� �Ѱ����� ������ ���޵� ���� �����ϴ� ���̹Ƿ� ���� ���� �����ϴ� ���� �ƴϴ�. 
//	(�湮 ��� �� 0 ��µ�)
void dfs(int cur_x, int cur_y, int& cnt) {
	visited[cur_x][cur_y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int new_x = cur_x + dx[i];
		int new_y = cur_y + dy[i];

		if (canGo(new_x, new_y)) {
			dfs(new_x, new_y, cnt);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			if (grid[i][j] != 0 && !visited[i][j]) {
				dfs(i, j, cnt);
				// dfs Ž�� ��� �� ���� ��带 Ž���ߴ��� ���Ϳ� ����
				town_size.push_back(cnt);
			}
		}
	}

	sort(town_size.begin(), town_size.end());

	cout << town_size.size() << '\n';

	for (auto& num : town_size)
		cout << num << '\n';

	return 0;
}