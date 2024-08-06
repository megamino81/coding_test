// 게임 맵 최단거리
// https://school.programmers.co.kr/learn/courses/30/lessons/1844?language=cpp

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n, m;
    
    n = maps.size();
    m = maps[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m, 0));
    visited[0][0] = 1;
    
    vector<pair<int,int>> next_path = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    
    queue<pair<int,int>> q;
    q.push({0, 0});

    // BFS
    while (!q.empty()) {
        int x, y;
        pair<int, int> p = q.front();
        q.pop();
        x = p.first;
        y = p.second;

        for (auto path : next_path) {
            int nx, ny;
            nx = x + path.first;
            ny = y + path.second;

            if (nx >= 0 && ny >= 0 && nx < n & ny < m) {
                if (maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }
    }
    if (visited[n-1][m-1] > 0) {
        answer = visited[n-1][m-1];
    } else {
        answer = -1;
    }
    return answer;
}

int main(int argc, char** argv)
{
    return 0;
}
