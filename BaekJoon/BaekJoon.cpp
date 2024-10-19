#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-19 ================
- 백준 
1644번 소수의연속합


*/
bool isPrime(int N) {
	bool isPrime = true;
	if (N == 2) return isPrime;
	for (int i = 2; i < N; ++i) {
		if (N % i == 0) {
			isPrime = false;
			break;
		}
	}
	return isPrime;
	//O(N)
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int>Primes;

	int sum{};
	for (int i = 2; i <= N; ++i) {
		if (isPrime(i)) {
			Primes.push_back(i);
		}
	}
	int size = Primes.size();
	vector<int>PrimeSum(size+1,0);
	for (int i = 1; i <= size; ++i) {
		PrimeSum[i] = PrimeSum[i - 1] + Primes[i-1];
	}
	int left = size-1;
	int right = size;
	int cnt{};

	while (left>=0) {
		int sum = PrimeSum[right] - PrimeSum[left];
		if (sum < N) {
			left--;
		}
		else if (sum > N) {
			right--;
		}
		else {
			cnt++;
			left--;
			right--;
		}
		
	}
	cout << cnt;
	


}


