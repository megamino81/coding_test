def solution(x, y, n):
  answer = 0
  s = set()
  s.add(x)
  
  while s:
    print("s:", s)  
    if y in s:
        print("y is in s")
        return answer
    nx = set()
    for i in s:
        if i+n <= y: nx.add(i+n)
        if i*2 <= y: nx.add(i*2)
        if i*3 <= y: nx.add(i*3)
    s = nx
    answer += 1 
    print ("nx:", nx)
    print ("answer:", answer)
  return -1

x = 2
y = 5
n = 4

print(solution(x, y, n))