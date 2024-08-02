// 친구관계 파악하기
// (백준 13023)

/*
N (노드 개수)
M (에지 개수)
A (그래프 데이터 저장 인접 리스트)
visited (방문 기록)
arrive (도착 확인 변수)


A 인접 리스트 크기 초기화
visited 배열 초기화

for(M의 개수만큼 반복) {
    인접 리스트 A에 그래프 데이터 저장
}

for(N의 개수만큼 반복) {
    노드마다 DFS 실행
    if (arrive) 
        반복 종료
}

if (arrive) 1 출력
else 0출력


DFS 구현
    if (길이가 5)
        arrive = true;
        함수 종료
    visited에 현재 노드 방문 기록
    현제 노드의 연결 노드 중 방문하지 않은 노드에 대해 DFS
    visited배열에 현재 노드 방문 삭제
*/

#include <iostream>
#include <vector>

using namespace std;


static vector< vector<int> > A;
static vector<bool> visited;
static bool arrive;

void DFS(int now, int depth);

int main(int argc, char** argv)
{
    int N, M;
    arrive = false;
    cin >> N >> M;
    A.resize(N);
    visited = vector<bool>(N, false);

    for (int i=0; i<M; i++) {
        int s, e;
        cin >> s >> e;
        // 양방향 저장 필요
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i=0; i<N; i++) {
        DFS(i, 1);
        if (arrive) break;
    }

    if (arrive) cout << 1 << "\n";
    else cout << 0 << "\n";

    return 0;
}

void DFS(int now, int depth)
{
    if (depth == 5) {
        arrive = true;
        return;
    }
    visited[now] = true;

    for (int i : A[now]) {
        if (!visited[i]) {
            DFS(i, depth + 1);
        }
    }
    visited[now] = false;
}