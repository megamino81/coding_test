def solution(sequence, k):
  answer = []
  l = len(sequence)
  for i in range(l):
    sum = 0
    start = end = i
    for j in range(i, l):
      sum += sequence[j]
      print (start, end, sum)
      if sum > k:
          start += 1
      elif sum < k:
          end += 1
      else:
          answer = [start, end]
          break
    if answer != []:
      break
  return answer

s = [1, 2, 3, 4, 5]
k = 7

s = [2, 2, 2, 2, 2]
k = 6
print(solution(s, k))
