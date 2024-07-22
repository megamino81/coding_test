
#떡 개수와 요청한 떡 길이 입력
#n, m = list(map(int, input().split()))
#각 떡의 높이 입력
#arr = list(map(int, input().split()))

n, m = 4, 6
arr = [10, 15, 19, 17]

start = 0
end = max(arr)

result = 0
while (start <= end):
    total = 0
    mid = (start + end) // 2
    for x in arr:
        if x > mid:
            total += x - mid
    if total == m:
        result = mid
        break
    elif total < m:
        end = mid - 1
    else:
        result = mid
        start = mid + 1

print(result)