#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- 백준 9506 약수 구하기

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input{};
	int add{};
	
	while (1) {
		vector<int> numbers{};
		add = 0;
		cin >> input;
		if (input < 0)break;
		
		for (int i = 1; i < input; ++i) {
			if (input % i == 0) { 
				numbers.push_back(i);
				add += i;
			}
		}
		if (add == input) {
			cout << input << " = ";
			for (int i = 0; i < numbers.size(); ++i) {
				if (i != numbers.size() - 1)cout << numbers[i] << " + ";
				else cout << numbers[i];
			}
			cout << '\n';
		}
		else {
			cout << input << " is NOT perfect.\n";
		}

	}
}


