#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- ���� 2501 ��� ���ϱ�

p, q �ڿ��� 
N�� 1�� 10000����
K�� 1�� N����
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	int cnt{};
	bool found = false;
	for (int i = 1; i <= N; ++i) {
		if (N % i == 0) cnt++;
		if (cnt == K) {
			cout << i;
			found = true;
			break;
		}
	}
	

	if (!found)cout << '0';


}


