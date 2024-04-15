// https://www.codetree.ai/missions/2/problems/1-2-5-plus/description
// 1,2,5 ���ϱ�
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int num[3] = { 1,2,5 };
int dp[1001];

int main() {
	cin >> n;

	// 1,2,5�� �ڱ� ���ڿ� ���� ��������� ��� 1������ ������ ������
	for (int i = 0; i < 3; i++)
		dp[num[i]] = 1;

	// �������� ������ �ٸ��� �ٸ� ������
	// ���������� ���� ����� ����� ������ dp[i]�� ��� �����ָ� �ȴ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i >= num[j]) {
				dp[i] += dp[i - num[j]];
				dp[i] %= 10007;
			}
		}
	}

	cout << dp[n];
	return 0;
}