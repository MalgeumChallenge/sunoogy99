// https://www.codetree.ai/missions/2/problems/coin-change/description
// ���� �Ž����ֱ�
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int coin[101];
int dp[10001];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	// INT_MAX�� �ʱ�ȭ�ϸ� INT_MAX + 1�� �ּڰ����� �ٲ�� ����
	// overflow ������ �ٸ� ������� �ʱ�ȭ�� 
	// memset �� �Դ� �Ŵ� �˾ƺ��� �� (�̻��� ������ �ʱ�ȭ��..)
	for (int i = 1; i <= m; i++) {
		dp[i] = 99999;
	}

	dp[0] = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= coin[j]) {
				if (dp[i - coin[j]] == 99999) 
					continue;

				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}

	int ans = dp[m];
	if (ans == 99999)
		ans = -1;
	
	cout << ans;

	return 0;
}