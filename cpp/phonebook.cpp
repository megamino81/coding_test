// 전화번호 목록
// https://school.programmers.co.kr/learn/courses/30/lessons/42577?language=cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    // 번호가 바로 앞의 번호를 포함하는지 체크
    for (int i=0; i<phone_book.size()-1; i++) {
        string curr = phone_book[i];
        string next = phone_book[i+1];

        next = next.substr(0, curr.size());

        if (curr == next) {
            return false;
        }
    }
    return answer;
}