def solution(bridge_length, weight, truck_weights):
  answer = 0

  # 다리를 만들자, 일단 전체를 길이만큼 0으로 세팅
  bridge_que = [0] * bridge_length
  cur_weight = 0

  # trucks.pop(0) 대신 pop()을 사용하기 위해 뒤집기
  truck_weights = truck_weights[::-1]

  while truck_weights:
    answer += 1

    # 다리위에서 트럭 한대가 빠려나갔으니까 무게 빼줌
    cur_weight -= bridge_que.pop(0)

    # 만약 현재 무게에서 트럭이 한대 더 들어와도 다리가 버틸 수 있다면
    # 트럭을 다리에 추가시키고
    # 아니면 0으로 세팅
    if cur_weight + truck_weights[-1] <= weight:
      w = truck_weights.pop()
    else:
      w = 0

    cur_weight += w
    bridge_que.append(w)

  # 트럭이 다리에 다 올라갔으면 다리 길이만큼 초를 증가
  return answer + len(bridge_que)


print(solution(2, 10, [7,4,5,6]))
print(solution(100, 100, [10,10,10,10,10,10,10,10,10,10]))
