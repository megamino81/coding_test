''' 
입력
hit cog

hot
dot
dog
lot
log
cog

idea
3개중 2개가 같으면 변환 가능
단어의 길이 - 1 가 같으면 변환 가능


출력
최소 몇단계
'''
from collections import deque

def solution(begin, target, words):
    answer = 0

    q = deque()
    # 첫 시작 위치는 처음 단어로 하고, 현재 단어가 몇번 바뀌었는지에 대한 정보를 가지도록.
    q.append([begin, 0])
    visited = [0] * len(words)

    while q:
        # q에서 데이터를 꺼낸 다음
        word, cnt = q.popleft()
        print('word:', word)
        print('cnt:', cnt)


        # target 단어가 찾아지면 cnt 리턴
        if word == target:
            return cnt

        # 각 단어와 비교해서 몇 글자가 차이 나는지 비교
        for i in range(len(words)):
            if not visited[i]:
                s = 0
                print ("compare, word1:", word)
                print ("compare, word2:", words[i])
                for x, y in zip(word, words[i]):
                    if x != y: s += 1
                # 1글자만 차이날 경우
                # q에 해당 단어를 넣고 cnt증가, 방문처리
                #if sum(x != y for x, y in zip(word, words[i])) == 1: 
                if s == 1:
                    q.append([words[i], cnt+1])
                    visited[i] = 1
                    print('only 1 char different, append q')
        print('')
    return answer

print(solution('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog']))