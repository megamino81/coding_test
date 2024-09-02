// 구명보트
// https://school.programmers.co.kr/learn/courses/30/lessons/42885?language=cpp

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int min_index = 0;
    int max_index = people.size() - 1;

    while (max_index >= min_index) {
        if (people[max_index] + people[min_index] <= limit) {
            answer ++;
            max_index --;
            min_index ++;
        } else {
            answer ++;
            max_index --;
        }
    }
    return answer;
}

int main(int argc, char** argv)
{
    cout << solution({70,50,80,50}, 100);
    return 0;
}