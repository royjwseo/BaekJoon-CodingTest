#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- ���� 
1978�� �Ҽ� ã��

N���� �� �߿� �Ҽ� ã��. N�� 100����, N��ü�� 1000���� �ڿ���
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	int input;
	int cnt{};
	
	for (int i = 0; i < num; ++i) {
		bool is_Prime = true;
		cin >> input;
		if (input == 1)continue;
		if (input == 2) {
			cnt++;
			continue;
		}
		for (int i = 2; i < input; ++i) {
			if (input % i == 0) {
				is_Prime = false;
				break;
			}
		}
		if(is_Prime) cnt++;

	}
	
	cout << cnt;
}


