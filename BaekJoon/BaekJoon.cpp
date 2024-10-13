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
11653 ���μ�����

���� N ���μ����� ��� �������� ���
*/

bool is_Prime(int num) {

	if (num < 2)return false;

	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0)return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int num;
	while (1) {
		if (N == 1)break;
		for (int i = 2; i <= 10'000'000; ++i) {
			if (N % i==0) { 
				cout << i << '\n'; 
				N /= i;
				break;
			}
		}
		
	}

	

}


