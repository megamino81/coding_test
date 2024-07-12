import java.util.Stack;
import java.util.LinkedList;

class Solution {
    public int solution(int n, int[] nums) {
        
        // 1. 방문 검사 배열
        boolean[] visited = new boolean[n];
        Stack<Integer> stack = new Stack<>();
        
        // 2. 초기 상태
        visited[0] = true;
        //stack.add(0);
        stack.push(0);
        
        // 3. 탐색 진행  
        while (!stack.isEmpty()) {
            int state = stack.pop();
            
            // 4. 중복 검사
            if (visited[state]) {
            continue;
            }
            visited[state] = true;
            
            // 5. 현재 상태 처리
            
            // 6. 다음 상태 탐색, 전이 상태 생성
            for (int next : nums) {
                // 7. 범위 검사
                if (! /* 범위 검사 조건 */) {
                   continue;
                }
                
                // 8. 유효성 검사
                if (! /* 유효성 검사 */) {
                    continue;
                }
                
                // 9. 상태 전이
                stack.push(next);
            }
        }
    }
}