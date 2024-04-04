// https://www.codetree.ai/missions/2/problems/maximum-number-of-jumps/description
// �ִ� ���� Ƚ��
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int max_val = INT_MIN;
int arr[1001];
int dp[1001];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			// ��������κ��� ���� ������ �����̹Ƿ� ���߿� �����
			// �ش� �κ��� ��������� ���� ������ ������ �ƴ�
			// dp[j] != -1 ���� �߰���
			if (j + arr[j] >= i && dp[j] != -1) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			// if (dp[j] == INT_MIN) continue; �� ���� ���� ������ �ϴ� ����
			// �� �ڵ带 �����ϱ� ���� ����
		}
	}

	for (int i = 1; i <= n; i++) {
		max_val = max(max_val, dp[i]);
	}

	cout << max_val;
	return 0;
}