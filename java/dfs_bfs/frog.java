import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;

    private static int N, A, B;
    private static int []bridge;

    static class Jump {
        int idx, cnt;

        public Jump(int idx, int cnt) {
            super();
            this.idx = idx;
            this.cnt = cnt;
        }

        @Override
        public String toString() {
            return "Jump [idx=" + idx + ", cnt=" + cnt + "]";
        }

    }

    private static int bfs() {
        Queue<Jump> queue=new LinkedList<>();
        queue.add(new Jump(A, 0));

        boolean []visited=new boolean[N+1];
        visited[A]=true;

        while(!queue.isEmpty()) {
            Jump j=queue.poll();

            if(j.idx==B) {
                return j.cnt;
            }
            int now=1;
            while(true) {	// 오른쪽
                int val=now*bridge[j.idx];
                if(val+j.idx>N) break;
                if(!visited[val+j.idx]) {
                    visited[val+j.idx]=true;
                    queue.add(new Jump(val+j.idx, j.cnt+1));
                }
                now++;
            }

            now=1;
            while(true) {	// 왼쪽
                int val=now*bridge[j.idx];
                if(j.idx-val<=0) break;
                if(!visited[j.idx-val]) {
                    visited[j.idx-val]=true;
                    queue.add(new Jump(j.idx-val, j.cnt+1));
                }
                now++;
            }
        }
        return -1;
    }
}

출처: https://sujin7837.tistory.com/449 [sujin's 개발 로그:티스토리]