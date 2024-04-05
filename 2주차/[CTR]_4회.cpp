// https://www.codetree.ai/missions/2/problems/longest-increasing-sequence-2d/description
// 2���� �ִ� ���� ����
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int n, m;
int arr[51][51];
int dp[51][51];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	// ������ ��ǥ�� 1ĭ���� ����
	dp[1][1] = 1;

	// 2���� �迭�� ���ؼ��� �� �����͸� ��ǥ ������ �ؾ� ��
	// ���� 4�� for�� ����Ͽ��� (x1,y1) = k, l - (x2,y2) = i, j
	for (int k = 1; k <= n; k++) {
		for (int l = 1; l <= m; l++) {
			if (dp[k][l] != -1) {
				for (int i = k + 1; i <= n; i++) {
					for (int j = l + 1; j <= m; j++) {
						if (arr[i][j] > arr[k][l]) {
							dp[i][j] = max(dp[i][j], dp[k][l] + 1);
						}
					}
				}
			}
		}
	}

	int max_val = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			max_val = max(max_val, dp[i][j]);
		}
	}

	cout << max_val;
	return 0;
}