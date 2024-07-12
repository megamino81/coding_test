def solution(clothes):
  from collections import Counter
  from functools import reduce

  cnt = Counter([kind for name, kind in clothes])
  print(cnt.values())
  print(cnt.keys())

  answer = reduce(lambda x, y: x*(y+1), cnt.values(), 1) - 1
  return answer


c = [["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]
print(solution(c))