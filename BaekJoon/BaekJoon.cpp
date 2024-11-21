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
10816 숫자 카드 2

1KB -> 1024바이트
1MB -> 1000KB -> 1024 * 1024 바이트 대략 262'144개 int저장가능
스택 크기 : 1MB
*/

//int find_lowest(int find,vector<int>& cards) {
//	int start = 0;
//	int end = cards.size();
//	int index = 0;
//	while (start < end) {
//		int middle = (start + end) / 2;
//
//		if (cards[middle] >= find) {
//			end = middle;
//		}
//		else {
//			start = middle + 1;
//		}
//	}
//	return start;
//}
//int find_highest(int find, vector<int>& cards) {
//	int start = 0;
//	int end = cards.size() ;
//	int index = 0;
//	while (start < end) {
//		int middle = (start + end) / 2;
//
//		if (cards[middle] > find) {
//			end = middle;
//		}
//		else {
//			start = middle + 1;
//		}
//	}
//	return start;
//}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int M;
	cin >> N;
	vector<int>cards(N);
	for (int i = 0; i < N; ++i) {
		cin >> cards[i];
	}
	cin >> M;
	vector<int>cards2(M);
	for (int i = 0; i < M; ++i) {
		cin >> cards2[i];
	}
	sort(cards.begin(), cards.end());//50만 곱하기 log(50만) 천만

	for (int i = 0; i < M; ++i) {
		cout << upper_bound(cards.begin(),cards.end(), cards2[i]) - lower_bound(cards.begin(), cards.end(), cards2[i]) << ' ';
	}
	

}


