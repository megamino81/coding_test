import heapq

def heapsort(iterable):
  h = []
  result = []
  for v in iterable:
    heapq.heappush(h, v)

  for i in range(len(h)):
    result.append(heapq.heappop(h))

  return result

n = int(input())
arr = []

for i in range(n):
  arr.append(int(input()))

res = heapsort(arr)

for i in range(n):
  print(res[i])

