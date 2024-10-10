#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-10 ================
- 백준 단계별로 풀어보기 일반 수학 1

2292번

*/


int main() {

	int N{};
	cin >> N;
	int cnt{};
	int imsi{};
	while (1) {
		N = N - 6 * cnt++;
		if (N <= 1)break;
	}
	cout << cnt;

}


