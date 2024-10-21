#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

/*
================= 2024-10-21================
- 백준 
19532번 수학은 비대면강의입니다
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // 판별식 계산
    double denominator = a * e - b * d;

    if (denominator == 0) {
        // a/e와 b/f가 같은지 확인
        if (a * f == c * d && b * f == c * e) {
            cout << "LINE" << endl; // 무한 해
        }
        else {
            cout << "NONE" << endl; // 해 없음
        }
    }
    else {
        // 유일한 해를 구함
        int x = (c * e - b * f) / denominator;
        int y = (a * f - c * d) / denominator;
        cout << x << " " << y << endl; // 해 출력
    }


}

