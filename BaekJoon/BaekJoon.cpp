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
24265�� �˰��� ���� - �˰����� ���� �ð� 4

n 1~500'000

MenOfPassion(A[], n) {
	sum <- 0;
	for i <- 1 to n
		for j <- 1 to n
			for k <- 1 to n
				sum <- sum + A[i] �� A[j] �� A[k]; # �ڵ�1
	return sum;
}
*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	long long n;
	cin >> n;

	cout << n* (n *n)<<'\n';
	cout << 3;
		

}


