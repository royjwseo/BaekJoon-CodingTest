#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
================= 2024-10-12 ================
- ���� 
1085�� ���簢�� Ż��

����ġ x,y 
���� �Ʒ� 0,0
������ �� w,h (1<= <=1000)

*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> x >> y;

	int w, h;
	cin >> w >> h;

	int width_distance{};
	int height_distance{};

	if (w - x > x)width_distance = x;
	else width_distance = w - x;
	
	if (h - y > y)height_distance = y;
	else height_distance = h - y;

	if (width_distance > height_distance)cout << height_distance;
	else cout << width_distance;
	

}


