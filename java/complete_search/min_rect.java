/*
  Math.max
  Math.min
*/
// 반복하면서 두 수중 큰수가 length, 가장 큰 length 구하기
// 두수중 작은수가 height, 가장 큰 height 구하기
class Solution {
    public int solution(int[][] sizes) {
        int length = 0, height = 0;
        for (int[] card : sizes) {
            length = Math.max(length, Math.max(card[0], card[1]));
            height = Math.max(height, Math.min(card[0], card[1]));
        }
        int answer = length * height;
        return answer;
    }
}