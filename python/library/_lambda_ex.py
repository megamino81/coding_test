
'''
answer = reduce(lambda x, y: x*(y+1), cnt.values(), 1) - 1
'''

s = [1, 3, 4, 8, 13, 17, 20]
ss = [3, 4, 8, 13, 17, 20]
sorted(list(zip(s, ss)), key=lambda i: i[0])
sorted(list(zip(s, ss)), key=lambda i: i[1]-i[0])


