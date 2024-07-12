def solution(s):
  answer = ''
  words = s.split(" ")
  result = []

  for w in words:
    if w != "":
      result.append(w[0].upper() + w[1:].lower())
    else:
      result.append("")
  answer = " ".join(result)

  return answer


print(solution("3people unFollowed me"))
print(solution("for the last week"))