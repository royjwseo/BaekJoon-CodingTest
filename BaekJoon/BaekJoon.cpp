#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- 백준 2501 약수 구하기

p, q 자연수 
N은 1과 10000사이
K는 1과 N사이
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


