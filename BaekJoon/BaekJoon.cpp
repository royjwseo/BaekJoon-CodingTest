#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- ���� 11659 ���� �� ���ϱ�
�ð� ���� 1�� (1�� ����)
1<=N<=10��
1<=M<=10��
�˰��� ���� �ܼ��� ���� �� ���� �־��� ��� N*M-> 10�� ���� 
�չ迭 �̿��Ͽ� O(N+M)���� ���̱�
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,M;
	cin >> N >> M;

	vector<int> added_numbers(N+1, 0);
	int input{};
	for (int i = 1; i <= N; ++i) {
		cin >> input;
		added_numbers[i] = added_numbers[i-1] + input;
	}

	int x, y;
	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		cout << added_numbers[y] - added_numbers[x - 1] << '\n';
	}
}


