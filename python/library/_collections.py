'''
# deque
deque는 덱(double ended queue) 기능을 제공 
인덱싱, 슬라이싱 불가

연속적으로 나열된 데이터의 시작 부분이나 끝 부분에
데이터 삽입/삭제 효과적
'''

# popleft()
# pop()
# appendleft(x)
# append(x)
from collections import deque


'''
Counter
해당 원소에 대한 Count를 dict로 반환
'''
from collections import Counter
data = ['A','B','A','B','A','B','A','A','B','A','A','B','A','A']
counter = dict(Counter(data))
print(counter)
# >>> {'A': 9, 'B': 5}


