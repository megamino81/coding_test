'''
문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.

입출력 예
tickets	
[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]
return
["ICN", "JFK", "HND", "IAD"]

tickets	
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]
return
["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]

'''

from collections import defaultdict

def dfs(graph, path, visit):
    print ("path:", path)
    print ("visit:", visit)
    if path:
        to = path[-1]
        if graph[to]:
            path.append(graph[to].pop(0))
        else:
            visit.append(path.pop())
        dfs(graph, path, visit)
    return visit[::-1]

def solution(tickets):
    answer = []

    graph = defaultdict(list)

    for a, b in tickets:
        graph[a].append(b)  
    for key in graph.keys():
        graph[key].sort()

    print(graph)        
    answer = dfs(graph, ["ICN"], [])
    return answer


def _solution(tickets):
    routes = {}
    for t in tickets:
        routes[t[0]] = routes.get(t[0], []) + [t[1]]
    for r in routes:
        routes[r].sort()

    # routes: {'ICN': ['SFO', 'ATL'], 'SFO': ['ATL'], 'ATL': ['SFO', 'ICN']}
    print(routes)


    # tickets: [["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]

# 풀이 순서
# ICN을 먼저 스택에 넣기
# 1. 스택 top을 보고 거기서부터 갈 수 있는 공항들을 tickets에서 검색.
# ** 스택에서 꺼내지 않음. 즉 pop이 아니고 top
# 2. 여러 개 있을 경우 알파벳 순서가 높은 것을 하나 넣기(ex: ATL, SOF 라면 ATL을 선택)
# 3. 스택에 넣은 경로(ex: ICN-ATL)는 tickets에서 제거
# 4. tickets의 경로가 모두 제거될 때까지 1 ~ 3번을 반복
# tickets에서 모든 경로가 다 제거된 후 스택을 출력하면 끝

    stack = ["ICN"]
    path = []
    while len(stack) > 0:
        city = stack[-1]

        # 가장 마지막 도시일 경우
        if city not in routes or len(routes[city]) == 0:
            path.append(stack.pop())
        else:
            stack.append(routes[city].pop(0))
        print("path:", path)
        print("stack:", stack)
        print("routes:", routes)
        print("")

    return path[::-1]


print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))