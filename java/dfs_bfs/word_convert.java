import java.util.Queue;
import java.util.LinkedList;

class Solution {
    private class State {
        public final String word;
        public final int step;
        private State(String word, int step) {
            this.word = word;
            this.step = step;
        }
    }

    private boolean isConvertable(String src, String dst) {
        char[] srcArr = src.toCharArray();
        char[] dstArr = dst.toCharArray();

        int diff = 0;
        for (int i=0; i<srcArr.length; i++) {
            if (srcArr[i] != dstArr[i]) diff ++;
        }
        return diff == 1;
    }

    public int solution(String begin, String target, String[] words) {
        // 1. 상태 정의, 필요할 경우 class 추가

        // 2. 방문 검사 배열
        boolean[] visited = new boolean[words.length];
        Queue<State> queue = new LinkedList<>();

        // 3. 초기 상태
        //visited[0] = true;
        queue.add(new State(begin, 0));

        // 4. 탐색 진행
        while (!queue.isEmpty()) {
            State state = queue.poll();

            // 5. 현재 상태 state 처리
            if (state.word.equals(target)) {
                return state.step;
            }

            // 6. 다음 상태 탐색, 전이 상태 생성

            for (int i=0; i<words.length; i++) {
                String next = words[i];

                /* 유효성 검사 */
                if (!isConvertable(state.word, next)) {
                    continue;
                }

                // 중복 검사
                if (visited[i]) {
                    continue;
                }

                // 방문 처리, 상태 전이
                visited[i] = true;
                queue.add(new State(next, state.step + 1));
            }
        }
        return 0;
    }   
}