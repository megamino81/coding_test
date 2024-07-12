def solution(participant, completion):
  answer = ''
  name_list = list(set(participant) - set(completion))
  print(name_list)
  answer = name_list[0]
  return answer

p = ["mislav", "stanko", "mislav", "ana"]	
c = ["stanko", "ana", "mislav"]

print(solution(p, c))