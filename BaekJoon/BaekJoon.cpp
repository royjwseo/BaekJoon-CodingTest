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
2869��

������-> V���� ���� ���� ���� �ö�
���� A����, �㿣 B���� �̲�����, ���� ���޽� �̲�������X
�������� ��ĥ�ɸ�����.

--�ذ� ���--

*/

int main() {
	int A{}, B{}, V{};
	cin >> A >> B >> V;

	int total_meter{};

	int one_Day_Up = A - B;
	int day_Cnt{};
	

	if (V - A > one_Day_Up) {
		day_Cnt += (V-A) / one_Day_Up+1;

	}	
	else
		day_Cnt = V / one_Day_Up + 1;
	
	cout << day_Cnt;
}


