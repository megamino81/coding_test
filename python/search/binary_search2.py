
def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None


#  원소의 개수와  target 입력
n, target = list(map(int, input().split()))
#  원소 입력
arr = list(map(int, input().split()))
result = binary_search(arr, target, 0, n-1)

if result == None:
    print("No result")
else:
    print("index=" + str(result))
    print("answer=" + str(result+1))
