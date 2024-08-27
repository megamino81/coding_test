// 피로도
// https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count = 0;
bool visited[8] = {false};

void dfs(int depth, int k, vector<vector<int>> dungeons)
{
    for (int i=0; i<dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(depth + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
    count = max(count, depth);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer;

    dfs(0, k, dungeons);
    answer = count;

    return answer;
}

int main(int argc, char** argv)
{
    vector<vector<int>> dungeons = {
        {80, 20},
        {50, 40},
        {30, 10}
    };
    cout << solution(80, dungeons);
    return 0;
}