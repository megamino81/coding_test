// 카펫
// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=cpp

#include <string>
#include <vector>
#include <iostream>


using namespace std;


/*
구하는 답을 [w, h] 라고 하면,
w와 h사이의 관계식

2w+2h-4=brown
(w-2)(h-2)=yellow
*/

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);

    int size = brown + yellow;
    for (int w=1; w<size; w++) {
        if (size % w != 0) continue;

        // 나누어 떨어지는 값중, 위 식을 만족하는 w, h 구하기
        int h = size / w;
        if ((w-2) * (h-2) == yellow) {
            answer[0] = max(w, h);
            answer[1] = min(w, h);
            break;
        }
    }

    return answer;
}

int main(int argc, char** argv)
{
    vector<int> answer1 = solution(10, 2);
    vector<int> answer2 = solution(24, 24);

    for (auto i : answer1)
        cout << i << " ";
    cout << endl;

    for (auto i: answer2)
        cout << i << " ";
    cout << endl;
    return 0;
}