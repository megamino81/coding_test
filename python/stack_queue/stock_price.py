# 1 2 3 2 3

# 4 3 1 1 0

def solution(prices):
    answer = []

    for i, p in enumerate(prices):
        t = 0
        for j, p1 in enumerate(prices[i+1:]):
            print("i,j:", i, j)
            if p1 < p:
                t += 1
                break 
            t += 1
        answer.append(t)
    return answer

def solution2(prices):
    answer = []
    n=len(prices)
    for i in range(n):
        c=0
        for j in range(i+1,n):
            print("i,j:", i, j)
            if prices[j]<prices[i]:
                c+=1
                break
            c+=1
        answer.append(c)
    return answer


print(solution([1,2,3,2,3])) # [4,3,1,1,0]
print(solution2([1,2,3,2,3])) # [4,3,1,1,0]

