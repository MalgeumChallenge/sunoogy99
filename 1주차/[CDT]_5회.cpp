// https://www.codetree.ai/missions/2/problems/puyo-puyo/description
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

int n, k;
int max_val = INT_MIN;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int grid[101][101];
bool visited[101][101];
vector<int> block[101];

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool canGo(int x, int y) {
	if (!InRange(x, y))
		return false;
	else if (grid[x][y] != k || visited[x][y])
		return false;
	else
		return true;
}

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
			// �ִ� ��ȣ�� ������ ����
			if (grid[i][j] > max_val) 
				max_val = grid[i][j];
		}
	}

	for (k = 1; k <= max_val; k++) {
		// cnt: ����� ��� ���� ����
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				/* 
					DFS Ž�� ������ ��� ����
					1. ���� Ž���ϴ� ���ڿ� ���� ���̾�� ��
					2. �湮���� ���� ��忩�� ��
				*/
				if (grid[i][j] == k && !visited[i][j]) {
					dfs(i, j, cnt);
					/*
						cnt, max_cnt �� �� cnt ���� ����
						k�� ���� ���� ���� dfs Ž�� �����Ѵٰ� �� ��,
						������� ���� ���� ������ �� ����
						�� �߿��� ���� ū �� ũ�⸦ �˾Ƴ��� �ϱ� ������
						max_cnt ����ϸ�, �� ���� ũ��� ���� ����ؾ� �ϹǷ�
						cnt ���� dfs�� ��ġ�� ������ �� 0���� �ٽ� �ʱ�ȭ �ؾ� ��
					*/
					block[k].push_back(cnt);
					cnt = 0;
				}
			}
		}

	}

	// pop_cnt : ������ �� ����
	// max_cnt : ������ �� �� ���� ū �� ũ��
	int pop_cnt = 0;
	int max_cnt = INT_MIN;

	for (int i = 1; i <= max_val; i++) {
		for (auto& num : block[i]) {
			if (num >= 4)
				pop_cnt++;
			if (num > max_cnt)
				max_cnt = num;
		}
	}

	cout << pop_cnt << ' ' << max_cnt << '\n';
	return 0;
}