#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- ���� 11660 ���� �� 2���� ���ϱ�
�ð� ���� 1�� (1�� ����)
1<=N<=1024
1<=M<=10��
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>>added_numbers(N + 1, vector<int>(N + 1, 0)); //[0]���� 0, 1���� ���� �� ������
	vector<vector<int>>input_numbers(N + 1, vector<int>(N + 1, 0));
	int input{};

	//���� : i,j�� 1���� ��ȿ �� -> 
	//added_numbers[i][j]= added_numbers[i-1][j] + added_numbers[i][j-1] - added_numbers[i-1][j-1] + input_numers[i][j]
	// �� �迭���� �ߺ� �� ���� ���� �迭 ���ϸ� ���ο� i,j �չ迭 ���� ���� �� �ְ�, �̰� ���� 1��, 1�࿡�� ����� �������� 0���� �ʱ�ȭ �ǹǷ�

	
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> input_numbers[i][j];
				added_numbers[i][j] = added_numbers[i][j - 1] + added_numbers[i - 1][j] - added_numbers[i - 1][j - 1] + input_numbers[i][j];
			}
		}

		int x1, x2, y1, y2;
		for (int i = 0; i < M; ++i) {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << added_numbers[x2][y2] - added_numbers[x1-1][y2] - added_numbers[x2][y1 - 1] + added_numbers[x1 - 1][y1- 1]<<'\n';
		}



}


