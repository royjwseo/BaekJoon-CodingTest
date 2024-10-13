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
2581�� �Ҽ� 

�ڿ��� M, N �ְ�, M <= ? <= N �ڿ��� �� �Ҽ��� ��� �Ҽ� ��, �ּҰ�

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


