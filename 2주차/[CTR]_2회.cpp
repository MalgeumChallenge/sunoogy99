// https://www.codetree.ai/missions/2/problems/longest-decreasing-subsequence/description
// �ִ� ���� �κ� ����
// �ִ� ���� �κ� �������� �ε�ȣ ���⸸ �ٲ�
#include <iostream>
#include <algorithm>	// max
#include <cstring>	// memset
#include <climits>	// INT_MIN
using namespace std;

int n;
int max_val = INT_MIN;
int arr[1001];
int dp[1001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

			if (dp[i] == -1) {
				dp[i] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		max_val = max(dp[i], max_val);
	}

	cout << max_val;
	return 0;
}