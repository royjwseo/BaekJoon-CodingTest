#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	int num;
	int B;
	string result;

	cin >> num >> B;

	int division = num;
	int percentage{};
	char imsi{};
	do {
		percentage = division % B;
		division = division / B;
		if (percentage >= 10) {
			imsi = percentage - 10 + 'A';
			result += imsi;
		}
		else {
			result += to_string(percentage);;
		}

	} while (division != 0);
	reverse(result.begin(), result.end());
	cout << result;



}


