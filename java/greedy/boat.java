import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;

        //무게 순으로 정렬
        Arrays.sort(people);

        int min_index = 0; //가장 가벼운 사람 위치
        int max_index = people.length - 1; //가장 무거운 사람 위치

        /*
         양 끝부터 탐색을 시작해서
         가장 무거운 사람과 가장 가벼운 사람의 무게 합이 limit를 넘지 않으면 
         정답 카운트 +하고 인덱스를 한칸씩 안쪽으로 이동,
         limit를 넘으면 정답 카운트 +하고 max_index만 이동
         모든 원소를 탐색할 때 까지 반복
         */
        while(max_index >= min_index) {
            if(people[max_index] + people[min_index] <= limit) {
                answer++;
                max_index--;
                min_index++;
            }
            else {
                answer++;
                max_index--;
            }
        }

        return answer;
    }
}