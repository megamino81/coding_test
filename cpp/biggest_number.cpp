// 가장 큰 수
// https://school.programmers.co.kr/learn/courses/30/lessons/42746?language=cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(string a, string b)
{
    if (b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> str_numbers;
    for(int i: numbers)
        str_numbers.push_back(to_string(i));
    
    sort(str_numbers.begin(), str_numbers.end(), compare);

    for (string a : str_numbers) {
        answer += a;
    }
    if (answer[0] == '0') {
        answer = "0";
    }
    return answer;
}

int main(int argc, char** argv)
{
    vector<int> numbers1 = {6, 10, 2};
    vector<int> numbers2 = {3, 30, 34, 5, 9};

    cout << solution(numbers1) << endl;
    cout << solution(numbers2) << endl;

    return 0;
}