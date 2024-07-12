import java.util.Stack;

class Solution1 {
    int answer;
    public int solution(int[] numbers, int target) {
        answer = 0;
        dfs(0, 0, numbers, target);
        return answer;
    }
    void dfs(int n, int sum, int[] numbers, int target) {
        if(n == numbers.length) {
            if(sum == target) 
                answer++;
            return;
        }

        dfs(n + 1, sum + numbers[n], numbers, target);
        dfs(n + 1, sum - numbers[n], numbers, target);
    }
}


class Solution {
    private static class State {
        public final int index;
        public final int acc;
        State(int index, int acc) {
            this.index = index;
            this.acc = acc;
        }
    }

    public int solution(int[] numbers, int target) {
        int answer = 0;
        Stack<State> stack = new Stack<>();
        stack.push(new State(0, 0));

        while (!stack.isEmpty()) {
            State s = stack.pop();

            if (s.index == numbers.length) {
                if (s.acc == target) {
                    answer ++;
                }
                continue;
            }
            stack.push(new State(s.index+1, s.acc - numbers[s.index]));
            stack.push(new State(s.index+1, s.acc + numbers[s.index]));
        }

        return answer;
    }
}