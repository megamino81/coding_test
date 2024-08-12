// 순서대로 방문하기
// https://softeer.ai/practice/6246

/*
n : n*n 격자 지도
m : 지점수

1은 벽으로 막혀있음
차량은 n x n 격자 내에서 m개의 지점을 순서대로 방문
상하좌우 인접한 칸으로 이동, 한번 지났던 지점은 다시 방문 안됨

차량이 이동 가능한 서로 다른 가지수를 구하라

입력)
3 3
0 0 0
0 0 0
0 0 1
3 1
1 2
2 3
==>
5

3 3
0 0 1
0 0 0
0 0 1
3 1
1 2
2 3
==>
1
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int place[5][5];
static bool visited[5][5];
static int dx[4] = {-1, 1, 0, 0};
static int dy[4] = {0, 0, -1, 1};
static int route_count = 0;

int N, M;
vector<pair<int,int>> store;

void dfs(int x, int y, int dest_index)
{
    if (visited[x][y])
        return;

    if (place[x][y] == 1) {
        return;
    }

    if (store[dest_index].first == x && store[dest_index].second == y) {
        if (dest_index == (M-1)) {
            route_count ++;
            return;
        }
        dest_index ++;
    }

    visited[x][y] = true;

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
            dfs(nx, ny, dest_index);
        }
    }
    visited[x][y] = false;
}

int main(int argc, char** argv)
{
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> place[i][j];
            visited[i][j] = false;
        }
    }

    for (int i=0; i<M; i++) {
        int x,  y;
        cin >> x >> y;
        store.push_back(make_pair(x, y));
    }

    // 지점1부터 DFS를 돌면서 지점2를 거쳐서 지점3 도착할 경우 Count 증가
    dfs(store[0].first, store[0].second, 1);

    cout << route_count << "\n";
    return 0;
}