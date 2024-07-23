'''itertools
'''
data  = ['A', 'B', 'C']

# permutations
# iterable에서 n개의 데이터를 모두 나열
# 중복 없음
from itertools import permutations
print (list(permutations(data, 3)))
'''
[
('A', 'B', 'C'), 
('A', 'C', 'B'), 
('B', 'A', 'C'), 
('B', 'C', 'A'), 
('C', 'A', 'B'), 
('C', 'B', 'A')
]
'''
# combinations
# iterable에서 n개의 데이터를 모두 나열
# 순서 없음
from itertools import combinations
print (list(combinations(data, 3)))
'''
[('A', 'B', 'C')]
'''

# product
# iterable에서 n개의 데이터를 모두 나열
# 중복 허용
from itertools import product
print (list(product(data, repeat=3)))
'''
[
('A', 'A', 'A'), ('A', 'A', 'B'), ('A', 'A', 'C'), 
('A', 'B', 'A'), ('A', 'B', 'B'), ('A', 'B', 'C'), 
('A', 'C', 'A'), ('A', 'C', 'B'), ('A', 'C', 'C'), 
('B', 'A', 'A'), ('B', 'A', 'B'), ('B', 'A', 'C'), 
('B', 'B', 'A'), ('B', 'B', 'B'), ('B', 'B', 'C'), 
('B', 'C', 'A'), ('B', 'C', 'B'), ('B', 'C', 'C'), 
('C', 'A', 'A'), ('C', 'A', 'B'), ('C', 'A', 'C'), 
('C', 'B', 'A'), ('C', 'B', 'B'), ('C', 'B', 'C'), 
('C', 'C', 'A'), ('C', 'C', 'B'), ('C', 'C', 'C')]
'''

