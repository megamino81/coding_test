// 최소직사각형
// https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int w = 0;
    int h = 0;

    for(auto s : sizes) {
        w = max(w, *max_element(s.begin(), s.end()));
        h = max(h, *min_element(s.begin(), s.end()));
    }

    int dimension = w * h;
    return dimension;
}

int main(int argc, char** argv)
{
    vector<vector<int>> sizes1 = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};

    cout << solution(sizes1) << endl;
    return 0;
}