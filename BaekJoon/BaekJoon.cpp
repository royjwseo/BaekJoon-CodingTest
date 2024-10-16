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
24267번 알고리즘 수업 - 알고리즘의 수행 시간 6

n 1~500'000

MenOfPassion(A[], n) {
	sum <- 0;
	for i <- 1 to n - 2
		for j <- i + 1 to n - 1
			for k <- j + 1 to n
				sum <- sum + A[i] × A[j] × A[k]; # 코드1
	return sum;

	이 코드는 모든 i, j, k에 대해 조합을 찾는 과정이므로, 세 루프의 수행 횟수는 약 n choose 3입니다. 이는 다음과 같이 표현할 수 있습니다:


n(n−1)(n−2)/6
​

따라서, **시간 복잡도는 O(n^3)**입니다.
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long n;
	cin >> n;

		
	long long cnt{};
	long long add{};
	for (int i = 1; i < n; ++i) {
		add += i-1;
		cnt += add;
	}


	cout << cnt<<'\n';
	cout << 3;

	//1 2 3 4 5  6  7
	//0 0 1 4 10 20 35
	// 0 1 3 6 10 15 

		
		

}


