import java.util.PriorityQueue;

class Solution {  
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> que = new PriorityQueue<>();
        for (int i=0; i<scoville.length; i++) {
            que.add(scoville[i]);
        }

        int count = 0;
        int min = que.peek();
        while (K > min && que.size() > 1) {
            count ++;

            int a = que.poll();
            int b = que.poll();
            int c = a + (b * 2);
            que.add(c);
            min = min = que.peek();
        }   

        if (K > min) {
            return -1;
        }

        return count;   
    }
}