// 장애물 인식 프로그램
// https://softeer.ai/practice/6282
/*
7
1110111
0110101
0110101
0000100
0110000
0111110
0110000

==>
3
7
8
9
*/

/*
N (지도 크기)
map (지도 인접 리스트)
visited (방문 기록)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static int N;
static vector<vector<int>> map;
static vector<vector<bool>> visited;
static int cnt = 0;

void DFS(int x, int y)
{
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 0)
            continue;

        if (visited[nx][ny])
            continue;
            
        visited[nx][ny] = true;
        cnt ++;
        DFS(nx, ny);
    }
}

int main(int argc, char **argv)
{
    vector<int> blockList;

    cin >> N;
    map = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%01d", &map[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j] || map[i][j] == 0)
                continue;
            visited[i][j] = true;
            cnt = 1;
            DFS(i, j);
            blockList.push_back(cnt);
        }
    }
    sort(blockList.begin(), blockList.end());
    
    cout << blockList.size() << "\n";
    for (auto &v : blockList)
        cout << v << "\n";

    return 0;
}