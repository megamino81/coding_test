'''
[
[1,0,1,1,1],
[1,0,1,0,1],
[1,0,1,1,1],
[1,1,1,0,1],
[0,0,0,0,1]
]
'''

from collections import deque

def solution(maps):
    answer = 0

    n = len(maps)
    m = len(maps[0])

    visited = [[0] * m for _ in range(n)]

    visited[0][0] = 1

    next_path = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    queue = deque()
    queue.append((0, 0))

    # bfs 

    while queue:
        x, y = queue.popleft()

        for path in next_path:
            nx = x + path[0]
            ny = y + path[1]

            if (nx >= 0) and (ny >= 0) and (nx < n) and (ny < m):
                if maps[x][y] == 1 and visited[nx][ny] == 0:
                    queue.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1
    answer = visited[n - 1][m -1] or -1
    return answer

print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]))