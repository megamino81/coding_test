import java.util.Stack;

class Solution {
  public int[] solution(int[] prices) {
    int answers = new int[prices.length];

    Stack<Integer> beginIdxs = new Stack<Integer>();
    int i=0;

    beginIdxs.push(i);
    for (i=1; i<prices.length; i++) {
      while(!beginIdxs.isEmpty() && prices[i] < prices[beginIdxs.peek()]) {
        int beginIdx = beginIdxs.pop();
        terms[beginIdx] = i - beginIdx;
      }
      beginIdxs.push(i);
    }

    System.

    while(!beginIdxs.isEmpty()) {
      int beginIdx = beginIdxs.pop();
      terms[beginIdx] = i - beginIdx - 1;
    }
    return terms;
  }
}