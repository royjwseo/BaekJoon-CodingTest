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
2581번 소수 

자연수 M, N 주고, M <= ? <= N 자연수 중 소수들 골라 소수 합, 최소값

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

	vector<int> primenumbers;

	int N, M;
	cin >> M >> N;


	for (int i = M; i <= N; ++i) {
		if (is_Prime(i)) primenumbers.push_back(i);
	}

	if (primenumbers.empty())cout << -1;
	else {

		int sum{};
		for (auto a : primenumbers) {
			sum += a;
		}
		cout << sum << '\n' << *min_element(primenumbers.begin(), primenumbers.end());
	}



}


