// 네트워크
// https://school.programmers.co.kr/learn/courses/30/lessons/43162?language=cpp


#include <string>
#include <vector>

using namespace std;

void DFS(int from, int n, vector<int>& visited, vector<vector<int>>& computers)
{
    for(int i=0; i<n; i++) {
        if (from != i && computers[from][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            DFS(i, n, visited, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n, 0);

    for (int i=0; i<n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        answer ++;
        visited[i] = 1;
        DFS(i, n, visited, computers);
    }
    return answer;
}

int main(int argc, char** argv)
{
    return 0;
}
