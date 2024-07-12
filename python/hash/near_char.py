def solution(s):
  alps = sorted(set("abcdefghijklmnopqrstuvwxyz") - set(skip))
  alps_num = len(alps) 
  result = '' 

  for char in s:
    result += alps[(alps.index(char)+index)%alps_num]


input = "bananab"
print(solution(input))