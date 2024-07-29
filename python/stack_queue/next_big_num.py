def solution(numbers):
  answer = [-1]*(len(numbers))
  stack = []
  for i in range(len(numbers)):
    while stack and numbers[stack[-1]] < numbers[i]:
      answer[stack.pop()] = numbers[i]
    stack.append(i)

  return answer

n = [2, 3, 3, 5] #	[3, 5, 5, -1]
print(solution(n))

#n = [9, 1, 5, 3, 6, 2]	 # [-1, 5, 6, 6, -1, -1]
#print(solution(n))
