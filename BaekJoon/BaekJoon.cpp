#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-14 ================
- ���� 
24262�� �˰��� ���� - �˰����� ���� �ð� 1

n 1~500'000
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int cnt{};

	while (n > 0) {
		n /= 2;
		cnt++;
	}
	
	cout << cnt<<'\n'<<cnt-1;

	
}


