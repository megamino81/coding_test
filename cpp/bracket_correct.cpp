// 올바른 괄호
// bracket_correct
// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    if (s[0] == ')') return false;

    stack<int> tmpStack;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') {
            tmpStack.push(s[0]);
        } else {
            if (tmpStack.empty()) {
                return false;
            } else {
                tmpStack.pop();
            }
        }
    }
    if (tmpStack.empty()) {
        return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    string s1 = "()()"; // true
    string s2 = "(())()"; // true
    string s3 = ")()("; // false
    string s4 = "(()("; // false

    cout << solution(s1) << endl;
    cout << solution(s2) << endl;
    cout << solution(s3) << endl;
    cout << solution(s4) << endl;

    return 0;
}