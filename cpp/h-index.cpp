// H-Index
// https://school.programmers.co.kr/learn/courses/30/lessons/42747?language=cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int hindex = 0;
    sort(citations.rbegin(), citations.rend());

    for (int c : citations) {
        if (c > hindex) {
            hindex ++;
        }
    }
    return hindex;
}

int main(int argc, char** argv)
{
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << solution(citations) << endl;

    return 0;
}