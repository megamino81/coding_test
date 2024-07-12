arr = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(arr, start, end):
  if start >= end:
    return

  pivot = start
  left = start + 1
  right = end

  while (left <= right):
    while(left <= end and arr[left] <= arr[pivot]):
      left += 1

    while(right > start and arr[right] >= arr[pivot]):
      right -= 1

    if (left > right):
      arr[right], arr[pivot] = arr[pivot], arr[right]
    else:
      arr[left], arr[right] = arr[right], arr[left]

  quick_sort(arr, start, right - 1)
  quick_sort(arr, right + 1, end) 

quick_sort(arr, 0, len(arr) - 1)
print(arr)


arr = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]
def quick_sort2(arr):
  if (len(arr)) <= 1:
    return arr

  pivot = arr[0]
  tail = arr[1:]

  left_side = [x for x in tail if x <= pivot]
  right_side = [x for x in tail if x > pivot]

  return quick_sort2(left_side) + [pivot] + quick_sort2(right_side)

print(quick_sort2(arr))