from collections import Counter
def solution(nums):
    answer = 0
    n = len(nums)/2
    s = dict(Counter(nums))
    print (s)
    sorted_counts = sorted(dict(Counter(nums)).items(), key=lambda x:x[1])
    print (sorted_counts)
    sum = 0
    for i in sorted_counts:
        sum += i[1]
        answer += 1
        if sum >= n:
            break
    return answer


a = 	[3, 3, 3, 2, 2, 4]
print(solution(a))