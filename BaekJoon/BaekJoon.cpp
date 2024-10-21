#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-21================
- 백준 
2798번 분해합
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int cnt{};
	int imsi = N;
	while (imsi != 0) {
		imsi /= 10;
		cnt++;
	}
	
	int sum{};
	int result{};
	int temp = N;
	while (temp > 0) {
		sum = temp;
		int calc = temp;
		for (int i = cnt - 1; i >= 0; --i) {
			int nums = calc / pow(10, i);
			calc -= nums * pow(10, i);
			sum += nums;
		}

		if (sum == N)result = temp;
		temp--;
	}
	cout << result;
	

	
}


