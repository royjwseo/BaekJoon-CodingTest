#include <iostream>
#include <string>
#include <numeric>
#include <sstream>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-12-03================
[정수론] 1929번 소수 구하기

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

bool isPrime(int a) {
	if (a % 2==0||a<=1)return false;
	if (a ==2)return true;
	int sqrtA = static_cast<int>(sqrt(a));
	for (int i = 3; i <= sqrtA; i+=2) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

void Eratosthenes(int start, int end) {
	vector<bool> isPrime(end + 1,true);
	isPrime[0] = false;
	isPrime[1] = false;


	for (int i = 2; i*i <= end; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= end; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = start; i <= end; ++i) {
		if (isPrime[i])cout << i << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;
	cin >> M >> N;

	Eratosthenes(M, N);

}

