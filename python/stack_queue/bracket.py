def solution(s):
  answer = True
  
  if not s.startswith('('):
      return False
  
  stack = []
  
  for c in s:
    if len(stack) == 0:
      stack.append(c)
      continue

    if c == '(':
      stack.append(c)
    else:
      o = stack.pop()

  print (stack)
  if len(stack) > 0:
    answer = False
  
  return answer