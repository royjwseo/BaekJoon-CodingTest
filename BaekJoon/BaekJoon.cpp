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

-- 2720��--
�׽�Ʈ ���̽� ���� T
���̽� �Ž����� C (����) ���� cent
���� 0.25�޷� ���� 0.1�޷� ���� 0.05�޷� ��� 0.01�޷�
�ּ����� �������� �Ž����ֱ�
*/


int main() {

	int TestCase;
	cin >> TestCase;
	int RefundTotal{};
	for (int i = 0; i < TestCase; ++i) {
		array<int, 4>CoinRefund{};
		cin >> RefundTotal;
		if (RefundTotal >=25) {
			CoinRefund[0]=RefundTotal / 25;
			RefundTotal = RefundTotal % 25;
		}
		if (RefundTotal >=10) {
			CoinRefund[1]=RefundTotal / 10;
			RefundTotal = RefundTotal % 10;
		}
		if (RefundTotal >=5) {
			CoinRefund[2]=RefundTotal / 5;
			RefundTotal = RefundTotal % 5;
		}
		if (RefundTotal >=1) {
			CoinRefund[3]=RefundTotal / 1;
			RefundTotal = RefundTotal % 1;
		}
		for (int Refund : CoinRefund) {
			cout << Refund << ' ';
		}
		cout << '\n';

	}
	

}


