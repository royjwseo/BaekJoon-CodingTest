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
2559 수열 




*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int>temperatures(N+1,0);
	int input{};
	for (int i = 1; i < N + 1; ++i) {
		cin >> input;
		temperatures[i] = temperatures[i - 1] + input;
	}
	int left = 0;
	int right = 0;
	int leftover;
	int max = INT_MIN;
	while (left <= N-K) {
		int sum= temperatures[left + K] - temperatures[left];
		if (sum > max) {
			max = temperatures[left + K] - temperatures[left];
		}	
		left++;
	}
	cout << max;
}


