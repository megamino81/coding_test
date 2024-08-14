// 기능 개발
// https://school.programmers.co.kr/learn/courses/30/lessons/42586

/*
입력:
3
90 30 55
1 30 5
==>
2 1

6
95 90 99 99 80 99
1 1 1 1 1 1
==> 
1 3 2

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int count = 0;

    while (progresses.size() > 0) {
        int elapsed = day * speeds[0];
        if (progresses[0] + elapsed >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            count ++;
        } else {
            if (count > 0) {
                answer.push_back(count);
                count = 0;
            }
            day ++;
        }
    }
    answer.push_back(count);
    return answer;
}


int main(int argc, char** argv)
{
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };

    vector<int> answer = solution(progresses, speeds);
    for(auto a: answer)
        cout << a << endl;
    return 0;
}