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
[코테 강의 1주차 문자열,누적합,구현] 1213번 팰린드롬 만들기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<char>left;
	deque<char>right;

	string input;
	cin >> input;

	array<int, 26> alpha{};
	for (char a : input) {
		alpha[a - 'A']++;
	}

	int mid=-1;
	for (int i = 0; i < 26; ++i) {
		int num = alpha[i];
		while (num > 1) {
			left.push_back('A' + i);
			right.push_front('A' + i);
			num -= 2;
		}
		if (num == 1) {
			mid = i;
		}
	}
	if(mid>=0)
	left.push_back('A' + mid);

	if (left.size() + right.size() < input.size())
	{
		cout << "I'm Sorry Hansoo";
	}
	else {
		for (char a : left) {
			cout << a;
		}
		for (char a : right) {
			cout << a;
		}
	}
	
}

