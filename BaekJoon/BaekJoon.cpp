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
[정수론] 4948 베르트랑 공준
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int Primes(int start) {
	vector<bool> isPrime(2 * start + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i <=2 * start; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 2 * start; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= start; ++i) {
		isPrime[i] = false;
	}
	int result = count_if(isPrime.begin(), isPrime.end(), [](const bool& a) {
		return a == true;
		});
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int input=-1;
	while (1) {
		cin >> input;
		if (input == 0)break;
		cout<<Primes(input)<<'\n';
	}
	
}

