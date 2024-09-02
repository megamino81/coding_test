// 큰 수 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/42883?language=cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    vector<char> stack;
    for(char c: number) {
        while (k > 0 && !stack.empty() && stack[stack.size() - 1] < c) {
            stack.pop_back();
            k --;
        }
        stack.push_back(c);
    }

    for (char c: stack) {
        answer += c;
    }
    return answer;
}

int main(int argc, char** argv)
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
    return 0;
}