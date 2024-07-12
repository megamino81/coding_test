import java.util.*;

class Solution1 {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;

        // 다리를 만들자, 일단 전체를 길이만큼 0으로 세팅
        Queue<Integer> bridge_que = new LinkedList<Integer>();
        for (int i=0; i<bridge_length; i++) {
            bridge_que.add(0);
        }

        // truck_weights 를 Queue로 변환
        Queue<Integer> truck_que = new LinkedList<Integer>();
        for (int i=0; i<truck_weights.length; i++) {
            truck_que.add(truck_weights[i]);
        }        

        System.out.println(bridge_que);
        System.out.println(truck_que);

        int cur_weight = 0;
        while (!truck_que.isEmpty()) {
            answer += 1;

            // 다리위에서 트럭 한대가 빠려나갔으니까 무게 빼줌
            cur_weight -= bridge_que.poll();


            // 만약 현재 무게에서 트럭이 한대 더 들어와도 다리가 버틸 수 있다면
            // 트럭을 다리에 추가시키고
            // 아니면 0으로 세팅
            int w;
            if (cur_weight + truck_que.peek() <= weight) {
                w = truck_que.poll();
            } else {
                w = 0;
            }
            cur_weight += w;
            bridge_que.add(w);

        }
        // 트럭이 다리에 다 올라갔으면 다리 길이만큼 초를 증가
        return answer + bridge_que.size();
    }
};


class Solution {
    class Truck {
        int weight;
        int move;

        public Truck(int weight) {
            this.weight = weight;
            this.move = 1;
        }

        public void moving() {
            move++;
        }
    }

    public int solution(int bridgeLength, int weight, int[] truckWeights) {
        Queue<Truck> waitQ = new LinkedList<>();
        Queue<Truck> moveQ = new LinkedList<>();

        for (int t : truckWeights) {
            waitQ.offer(new Truck(t));
        }

        int answer = 0;
        int curWeight = 0;

        while (!waitQ.isEmpty() || !moveQ.isEmpty()) {
            answer++;

            // moveQ가 비었을 경우 추가
            if (moveQ.isEmpty()) {
                Truck t = waitQ.poll();
                curWeight += t.weight;
                moveQ.offer(t);
                continue;
            }

            // moveQ에 있는 truck 이동
            for (Truck t : moveQ) {
                t.moving();
            }

            // moveQ의 첫번째 트럭의 move 값이 bridgeLength보다 클 경우
            // --> 다리는 다 건넜을 경우
            // moveQ에서 첫번째 트럭 제거
            // 현재 무게에서 해당 트럭 무게 빼기
            if (moveQ.peek().move > bridgeLength) {
                Truck t = moveQ.poll();
                curWeight -= t.weight;
            }

            // 대기 중인 트럭이 있고
            // 현재 무게 + 대기중인 트럭의 무게가 weight 이하일때
            // 대기중인 트럭을 moveQ로 이동, 무게 추가
            if (!waitQ.isEmpty() && 
                    curWeight + waitQ.peek().weight <= weight) {
                Truck t = waitQ.poll();
                curWeight += t.weight;
                moveQ.offer(t);
            }
        }

        return answer;
    }
}
