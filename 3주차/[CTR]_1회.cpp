// https://www.codetree.ai/missions/2/problems/select-segments-without-overlap-2/description
// ��ġ�� �ʰ� ���� ����
/* 
	���� ������ ����
	- ������ ������ �������� �����Ѵ�. 
	- ������ ������ �����ϴٸ�, ���������� ���� ū ���� �տ� ������ �����Ѵ�.
		����) ������ ������ ������ �� ���� ���̰� ���� ���� ���� �տ� ���� �ϱ� ����
	- ���� ������ ������ �������� ���� ������ ���� ������ �� Ŭ �� ��ġ�� �ʴ� ���� ������ ������Ų��.
	- DP ����� �ƴ� �׸��� �˰������� Ǯ���Ͽ���
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, total;
pair<int, int> arr[1001];
bool compare(pair<int, int>, pair<int, int>);	// pair �񱳸� ���� �� �Լ�

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	sort(arr + 1, arr + n + 1, compare);

	// arr[0]: (0, 0)
	// picked�� ������ ���õ� ������ �ε����� �����ϴ� ����
	int picked = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i].first > arr[picked].second) {
			total++;
			picked = i;
		}
	}

	cout << total;
	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}