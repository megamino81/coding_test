import java.util.Stack;

class Solution1 {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] chk = new boolean[n];
        for(int i = 0; i < n; i++) {
            if(!chk[i]) {
                dfs(computers, chk, i);
                answer++;
            }
        }
        return answer;
    }
    private void dfs(int[][] computers, boolean[] chk, int start) {
        chk[start] = true;
        for(int i = 0; i < computers.length; i++) {
            if(computers[start][i] == 1 && !chk[i]) {
                dfs(computers, chk, i);
            }
        }
    }
}

// Stack을 이용한 구현
class Solution {
    private void visitAll(int computer, int[][]computers, boolean[] visited) {
        Stack<Integer> stack = new Stack<>();
        stack.push(computer);

        while (!stack.isEmpty()) {
            int c = stack.pop();

            if (visited[c]) continue;
            visited[c] = true;

            for(int next=0; next<computers[c].length; next++) {
                if (computers[c][next] ==0) continue;
                stack.push(next);
            }
        }
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;

        boolean[] visited = new boolean[n];

        for (int i=0; i<n; i++) {
            if (visited[i]) continue;
            visitAll(i, computers, visited);
            answer ++;
        }

        return answer;
    }
}