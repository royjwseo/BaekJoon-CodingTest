#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- 백준 5086 배수와 약수

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a=1, b=1;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0)break;
		if (a > b) {
			if (a % b == 0)cout << "multiple\n";
			else cout << "neither\n";
		}
		else {
			if (b % a == 0)cout << "factor\n";
			else cout << "neither\n";
		}
	}
	

}


