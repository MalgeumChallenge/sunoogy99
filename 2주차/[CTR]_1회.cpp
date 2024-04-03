// https://www.codetree.ai/missions/2/problems/longest-increasing-subsequence/description
#include <iostream>
#include <algorithm>	// max 함수 사용
#include <cstring>		// memset 사용하여 배열 초기화
#include <climits>
using namespace std;

int n;
int max_val = INT_MIN;
int arr[1001];
int dp[1001];	// 최장 길이 저장

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			// 현재 위치 값이 앞에 놓인 숫자보다 커야 함
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		// 갱신되지 않은 위치는 해당 자리부터 카운트 시작 : 1 할당
		if (dp[i] == -1) {
			dp[i] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		max_val = max(dp[i], max_val);
	}

	cout << max_val;
	return 0;
}