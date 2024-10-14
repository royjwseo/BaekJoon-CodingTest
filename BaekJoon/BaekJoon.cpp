#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-14 ================
- 백준 
10101 삼각형 외우기



*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c > 180)cout << "Error";
	else if (a + b + c == 180) {
		if (a == b && b == c && c == a)cout << "Equilateral";
		else if (a != b && b != c && c != a) cout << "Scalene";
		else cout << "Isosceles";
	}
}


