from collections import defaultdict
def solution(topping):
  answer = 0
  ob = defaultdict(bool) #형쪽
  yb = defaultdict(int)  #동생쪽 (인트형)

  ## 처음엔 동생이 다 갖고 있다는 설정
  for i in topping:
    yb[i] += 1

  ## 동생쪽에서 하나씩 빼면서 형에게 전해준다.
  for i in topping:
    yb[i] -= 1
    ## 형쪽에서는 하나라도 받으면 True를 체크한다.
    ob[i] = True

    ## 동생쪽에서 특정 토핑이 0개가 되면, 해당 해쉬를 삭제한다.
    if yb[i] == 0:
      del yb[i]

    ## 토핑의 종류수만 비교
    if len(ob) == len(yb):
      answer +=1
      print("yb:", yb)
      print("ob:", ob)
  return answer

print(solution([1, 2, 1, 3, 1, 4, 1, 2]))