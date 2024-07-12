import java.util.ArrayList;

public class Solution {
  public int[] solution(int[] arr) {
    ArrayList<Integer> tempList = new ArrayList<>();
    
    int preNum = 10;
    for (int num : arr) {
      if (num != preNum) {
        tempList.add(num);
      }
      preNum = num;
    }

    int[] answer = new int[tempList.size()];
    for(int i=0; i<answer.length; i++) {
      answer[i] = tempList.get(i).intValue();
    }
    return answer;
  }
}