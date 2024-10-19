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
2470번 두 용액




*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	int N;
	cin >> N;
	vector<int>liquids(N);
	for (int i = 0; i < N; ++i) {
		cin >> liquids[i];
	}
	sort(liquids.begin(), liquids.end());

	int left = 0;
	int right = liquids.size() - 1;

	int max = INT_MAX;
	int left_index{}, right_index{};
	while (left < right) {
		int distance = abs(liquids[right]+liquids[left]);
		if (distance < max) {
			max = distance;
			right_index = right;
			left_index = left;
		}
		if (abs(liquids[left]) > abs(liquids[right])) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << liquids[left_index] << ' ' << liquids[right_index];

}


