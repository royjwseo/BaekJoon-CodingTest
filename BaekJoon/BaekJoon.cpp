#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-10 ================
- ���� �ܰ躰�� Ǯ��� �Ϲ� ���� 1
1193��

--�ذ� ���--
ó������ �迭�� ���� ����� �м��� �־� �ε��� ���Ϸ��ߴµ�, ������ �迭�� ����µ� �޸� ���� �� ���� ����
���� �밢���� ������ ã�µ� ¦�� �밢���϶� col �ε����� ����, Ȧ�� �밢���� �� row �ε��� ���� ���� ���

��� -> ���° �밢������ ã��, �ش� �밢���� ¦/Ȧ ���� ã�� , ¦/Ȧ�� ��� �ε����� ���� ���� ���

*/

//array<array<string, 3200>, 3200> table{};
int main() {
	
	/*for (int i = 0; i < 3200; ++i) {
		for (int j = 0; j < 3200; ++j) {
			table[i][j] = to_string(j + 1) + '/' + to_string(i + 1);
		}
	}
	*/

	int X;
	cin >> X;
	int cnt=1;
	int add = 1;

	bool up{};
	int i = 1;
	while (add < X) {
		add += ++i;
		cnt++;
	}
	int left = X - add+i;
	if (cnt % 2 == 0) {
		up = false;
	}
	else {
		up = true;
	}

	string result{};
	if (up) {
		//result = table[left - 1][cnt - left - 1];
		result = to_string(cnt - left + 1) + '/' + to_string(left);
	}
	else {
		//result = table[cnt-left - 1][left - 1];
		result = to_string(left ) + '/' + to_string(cnt - left + 1);
		//result = to_string(left) + '/' + to_string(cnt-left);
	}

	cout << result;

}


