// 출퇴근길
// https://softeer.ai/practice/6248

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> adj, bool reverse)
{
    cout << "print\n";
    for (int i=0; i<adj.size(); i++) {
        cout << i;
        if (reverse) cout << "<-- ";
        else cout << "--> ";
        for (int j=0; j<adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int cur, vector<bool> &visited, vector<vector<int>> map)
{
    if (visited[cur])
        return;
    visited[cur] = true;
    for (auto next : map[cur]) {
        dfs(next, visited, map);
    }
}

int main(int argc, char** argv)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n+1);
    vector<vector<int>> mapR(n+1);
    vector<bool> visited1(n+1, false);
    vector<bool> visited2(n+1, false);
    vector<bool> visited3(n+1, false);
    vector<bool> visited4(n+1, false);
    
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        mapR[y].push_back(x);
    }
    int s, t;
    cin >> s >> t;

    print(map, false);
    print(mapR, true);

    // 출근길에는 t을 1번만 방문
    // 퇴근길에는 s를 1번만 방문

    visited1[t] = true; // 출근
    visited2[s] = true; // 퇴근

    dfs(s, visited1, map);
    dfs(t, visited2, map);
    dfs(s, visited3, mapR);
    dfs(t, visited4, mapR);

    int count = 0;
    for (int i=1; i<=n; i++) {
        if (visited1[i] &&
                visited2[i] &&
                visited3[i] &&
                visited4[i]) {
            count ++;
        }
    }

    cout << count - 2; // S, T는 빼고 계산

    return 0;
}