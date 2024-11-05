#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
using namespace std;

/*
================= 2024-11-05================
pccp 모의고사 1번 - 외톨이 알파벳
*/


string solution(string input_string) {
    string answer = "";
    bool has_answer = false;
    for (int i = 0; i < input_string.size(); ++i) {
        bool continuous = true;
        char target = input_string[i];
        for (int j = i + 1; j < input_string.size(); ++j) {
            if (input_string[j] == target && input_string[j - 1] == target)continue;
            if (input_string[j] == target) {
                answer.push_back(target);
                has_answer = true;
                break;
            }
            else {
                continuous = false;
            }
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    if (!has_answer)answer = "N";

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
}


