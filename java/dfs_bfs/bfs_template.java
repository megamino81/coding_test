import java.util.Queue;
import java.util.LinkedList;

class Solution {
    public int solution(int n, int[] nums) {
        // 1. 상태 정의, 필요할 경우 class 추가
        
        // 2. 방문 검사 배열
        boolean[] visited = new boolean[n];
        Queue<Integer> queue = new LinkedList<>();
        
        // 3. 초기 상태
        visited[0] = true;
        queue.add(0);
        
        // 4. 탐색 진행
        while (!queue.isEmpty()) {
            int state = queue.poll();
            
            // 5. 현재 상태 state 처리
            
            // 6. 다음 상태 탐색, 전이 상태 생성
            
            for (int next : nums) {
                if (! /* 범위 검사 조건 */) {
                    continue;
                }
                
                if (! /* 유효성 검사 */) {
                    continue;
                }
                
                // 중복 검사
                if (visited[next]) {
                    continue;
                }
                
                // 방문 처리, 상태 전이
                visited[next] = true;
                queue.add(next);
            }
        }
    }
}