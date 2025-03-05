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
================= 2025-03-05================
1010번 다리 놓기
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

long long combination(int n, int r) {
	if (r > n - r) r = n - r; // C(n, r) == C(n, n-r) 최적화
	long long result = 1;
	for (int i = 0; i < r; ++i) {
		result *= (n - i);
		result /= (i + 1);
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		
		cout << combination(M,N) << '\n';


		
		
		
	}

}


