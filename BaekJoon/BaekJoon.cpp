#include <iostream>
#include <string>
#include <tuple>
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
================= 2025-03-06================
2839번 설탕 배달
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	//3kg 5kg 최대한 적은 봉지 

	int N;
	cin >> N;

	int cnt{};
	
	while (N % 5 != 0) {
		N -= 3;
		if (N < 0)break;
		cnt++;
	}
	if (N < 0)cout << -1;
	else {
		cnt += N / 5;
		cout << cnt;
	}


}


