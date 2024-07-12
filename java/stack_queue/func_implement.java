/*

LinkedList
    clear()
    peek() : 가장 첫번째 값
    offer(a)
*/

import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> q = new LinkedList<>();
        List<Integer> answerList = new ArrayList<>();

        for (int i = 0; i < progresses.length; i++) {
            // 1. 한 기능을 개발하는데 필요한 날짜 계산
            double remain = (100 - progresses[i]) / (double) speeds[i];
            int days = (int) Math.ceil(remain);

            // 2. 함께 배포할 기능 계산            
            if (!q.isEmpty() && q.peek() < days) {
                answerList.add(q.size());
                q.clear();
            }
            q.offer(days);
        }
        answerList.add(q.size());
        return answerList.stream().mapToInt(i -> i.intValue()).toArray();
    }
}
