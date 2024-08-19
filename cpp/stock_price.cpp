// 주식가격
// https://school.programmers.co.kr/learn/courses/30/lessons/42584?language=cpp

/*
입력:
1, 2, 3, 2, 3
==> 4, 3, 1, 1, 0
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    return answer;    
}

int main(int argc, char** argv)
{
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> answer = solution(prices);

    for(int a : answer) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}