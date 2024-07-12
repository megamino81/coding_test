import java.util.*;

public class Solution {
  public int solution(int[] priorities, int location) {
    int answer = 0;
    int l = location;
    
    Queue<Integer> que = new LinkedList<Integer>();
    for (int i : priorities) {
      que.add(i);  
    }

    Arrays.sort(priorities);
    int size = priorities.length - 1;

    while(!que.isEmpty()){
      Integer i = que.poll(); // same as pop(0)
      if (i == priorities[size]) {
        answer ++;
        l --;
        if (l < 0) break;
      } else {
        que.add(i);
        l --;
        if (l < 0)
          l = que.size() - 1;
      }
    }
    return answer
  }
}


import java.util.HashSet;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;

        List<Process> que = new ArrayList<Process>();
        for (int i=0; i<priorities.length; i++) {
            que.add(new Process(priorities[i], i));
        }

        while (!que.isEmpty()) {
            Process p = que.remove(0);
            if (que.stream().anyMatch(otherProc -> p.priority < otherProc.priority)) {
                que.add(p);
            } else {
                answer ++;
                if (p.location == location) {
                    break;
                }
            }
        }
        return answer;
    }

    class Process {
        int priority;
        int location;
        public Process(int priority, int location) {
            this.priority = priority;
            this.location = location;
        }
    }    
}