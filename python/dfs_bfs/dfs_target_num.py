def dfs(numbers, step, total, target):
  if step == len(numbers):
    if total == target:
      return 1
    else:
      return 0
  ret = 0
  #print (total, numbers)
  ret += dfs(numbers, step+1, total + numbers[step], target)
  ret += dfs(numbers, step+1, total - numbers[step], target)
  return ret

def solution(numbers, target):
  answer = dfs(numbers, 0, 0, target)
  return answer


print(solution([1,1,1,1,1], 3))
print(solution([4,1,2,1], 4))