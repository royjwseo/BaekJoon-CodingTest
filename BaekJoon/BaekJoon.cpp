#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-10 ================
- 백준 단계별로 풀어보기 일반 수학 1

-- 2720번--
테스트 케이스 개수 T
케이스 거스름돈 C (정수) 단위 cent
쿼터 0.25달러 다임 0.1달러 니켈 0.05달러 페니 0.01달러
최소한의 동전으로 거슬러주기
*/


int main() {

	int TestCase;
	cin >> TestCase;
	int RefundTotal{};
	for (int i = 0; i < TestCase; ++i) {
		array<int, 4>CoinRefund{};
		cin >> RefundTotal;
		if (RefundTotal >=25) {
			CoinRefund[0]=RefundTotal / 25;
			RefundTotal = RefundTotal % 25;
		}
		if (RefundTotal >=10) {
			CoinRefund[1]=RefundTotal / 10;
			RefundTotal = RefundTotal % 10;
		}
		if (RefundTotal >=5) {
			CoinRefund[2]=RefundTotal / 5;
			RefundTotal = RefundTotal % 5;
		}
		if (RefundTotal >=1) {
			CoinRefund[3]=RefundTotal / 1;
			RefundTotal = RefundTotal % 1;
		}
		for (int Refund : CoinRefund) {
			cout << Refund << ' ';
		}
		cout << '\n';

	}
	

}


