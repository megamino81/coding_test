#n, x = list(map(int, input().split()))
#arr = list(map(int, input().split()))

n, x = 7, 3
arr = [1, 1, 2, 2, 2, 2, 3]

count = [0] * max(arr)
for i in arr:
  count[i-1] += 1

print(count)
print("answer=" + str(count[x-1]))






from bisect import bisect_left, bisect_right

def count_by_range(a, left_value, right_value):
  right_index = bisect_right(a, right_value)
  left_index = bisect_left(a, left_value)
  return right_index - left_index

n, x = 7, 3
arr = [1, 1, 2, 2, 2, 2, 3]
print(count_by_range(arr, x, x))