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
[정수론] 2609번 최대공약수와 최소공배수
유클리드 호제법
1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int gcd(int a,int b) {

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;

	int gcd_result = gcd(A, B);
	cout << gcd_result <<'\n';
	cout << A * B / gcd_result;
}

