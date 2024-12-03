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
[정수론] 9020 골드바흐의 추측
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/
vector<bool> isPrime; 


void PrintPrimeAdds(int n) {

	
	int left{}, right{};
	for (int i = 2; i <= n/2; ++i) {
		if (isPrime[i]&&isPrime[n-i]) {
			left = i;
			right = n - i;
		}
	}
	cout << left << ' ' << right;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	isPrime.resize(10001, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i <= 10000; ++i) {
		if (isPrime[i]) {
			for (int j = i*i; j <= 10000; j += i) {
				isPrime[j] = false;
			}
		}
	}


	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		PrintPrimeAdds(n);
	}
	
}

