#include <iostream>
#include <string>
#include <array>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-21================
27433번 팩토리얼 2

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

int fibonacci(int i) {

	if (i <=0)return 0;
	else if (i == 1)return 1;

	return fibonacci(i-1) + fibonacci(i - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	cout<<fibonacci(n);
	
}


