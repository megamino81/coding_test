def solution(k, tangerine):
  answer = 0

  # 1 2 2 3 3 4 5 5
  # 1 2 3 4 5
  # 1 2 2 1 2

  d = {}
  for t in tangerine:
    if t in d: d[t] += 1
    else: d[t] = 1

  c_list = list(d.values())
  c_list.sort(reverse=True)

  sum = end = 0
  l = len(c_list)
  for start in range(l):
    while sum < k and end < l:
      sum += c_list[end]
      end += 1
    if sum == k:
      answer = len(c_list[start:end-1])

    sum -= c_list[start]
  return answer

k = 6
t = [1, 3, 2, 5, 4, 5, 2, 3]

print(solution(k, t))
