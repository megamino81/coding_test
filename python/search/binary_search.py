
def binary_search(arr, target, start, end):
  if start > end:
    return None
  mid = (start + end) // 2

  if arr[mid] == target:
    return mid
  elif arr[mid] > target:
    return binary_search(arr, target, start, mid-1)
  else:
    return binary_search(arr, target, mid+1, end)

#  원소의 개수와  target 입력
n, target = list(map(int, input().split()))
#  원소 입력
arr = list(map(int, input().split()))
result = binary_search(arr, target, 0, n-1)

if result == None:
  print ("No result")
else:
  print ("index=" + str(result))
  print ("answer=" + str(result+1))
  




