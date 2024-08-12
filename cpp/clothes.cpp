// 의상
// https://school.programmers.co.kr/learn/courses/30/lessons/42578?language=cpp

/*
풀이
경우의 수를 곱하기 위해 변수 초기화
옷을 종료별로 해시 테이블 만들기
해시 테이블에 존재하는 "옷종류 * (가짓수+1)"로 곱셈 진행, 이 값에 -1하여 출력
*/
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> cloth_map;

    for (auto c : clothes) {       
        cloth_map[c[1]] ++;
    }

    for (auto t : cloth_map) {
        answer *= (t.second + 1);
    }

    return answer - 1;
}

int main(int argc, char** argv) {
    vector<vector<string>> s = {
        {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}
    };

    cout << solution(s) << endl;

    vector<vector<string>> s1 = {
        {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}
    };

    cout << solution(s1) << endl;
    return 0;
}