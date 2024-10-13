#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- 백준 
1978번 소수 찾기

N개의 수 중에 소수 찾기. N은 100이하, N자체는 1000이하 자연수
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


