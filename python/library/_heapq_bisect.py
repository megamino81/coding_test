# heapq
'''
# heapq는 우선순위 큐 기능을 제공
# Please refer heap_sort.py
'''

# bisect
'''
# bisect는 이진 탐색 기능을 제공
# 정렬된 배열에서 특정한 원소를 찾을때
# bisect_left(a, x): 정렬된 순서를 유지하면서 리스트 a에 데이터 x를 삽입할 가장 왼쪽 인덱스를 찾음
# bisect_left(a, x): 정렬된 순서를 유지하면서 리스트 a에 데이터 x를 삽입할 가장 오른쪽 인덱스를 찾음
'''

from bisect import bisect_left, bisect_right
data = [1, 4, 5, 2, 2, 3, 19, 192, 39]
# [1, 2, 2, 3, 4, 5, 19, 39, 192]]
target = 2
bisect_left(data, target)
# >>> 1
bisect_right(data, target)
# >>> 5 