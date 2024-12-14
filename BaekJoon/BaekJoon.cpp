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
[코테 강의 1주차 문자열,누적합,구현] 2979 트럭 주차
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C;
	cin >> A >> B >> C;

	
	pair<int, int> first,second,third;
	cin >> first.first >> first.second;
	int max = first.second, min = first.first;
	cin >> second.first >> second.second;
	if (second.second > max)max = second.second;
	if (second.first < min)min = second.first;
	cin >> third.first >> third.second;
	if (third.first < min)min = third.first;
	if (third.second > max)max = third.second;

	
	

	vector<int>first_time(max+1, 0);
	vector<int>second_time(max+1, 0);
	vector<int>third_time(max+1, 0);
	
	for (int i = first.first; i <first.second; ++i) {
		first_time[i] = 1;
	}
	for (int i = second.first; i < second.second; ++i) {
		second_time[i] = 1;
	}
	for (int i = third.first; i < third.second; ++i) {
		third_time[i] = 1;
	}

	int result = 0;
	for (int i = min; i <= max; ++i) {
		int sum = first_time[i] + second_time[i] + third_time[i];
		if (sum == 1) {
			result += A;
		}
		else if (sum == 2) {
			result += 2*B;
		}
		else if(sum==3) {
			result += 3*C;
		}
	}
	cout << result;
	
}

