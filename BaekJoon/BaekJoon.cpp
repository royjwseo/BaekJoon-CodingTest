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
================= 2024-12-14================
[코테 강의 1주차 문자열,누적합,구현] 2309 일곱 난쟁이
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int>heights(9);
	for (int i = 0; i < 9; ++i) {
		cin >> heights[i];
	}
	sort(heights.begin(), heights.end());
	int sum=accumulate(heights.begin(), heights.end(),0);
	int left = 0;
	int right = 1;
	while (left<8) {
		int two_sum = heights[left] + heights[right];
		if (sum - two_sum == 100) {
			break;
		}
		else {
			right++;
			if (right > 8) {
				left++;
				right = left + 1;
			}
		}
	}

	for (int i = 0; i < 9; ++i) {
		if(i!=left&&i!=right)
		cout << heights[i] << '\n';
	}
}

