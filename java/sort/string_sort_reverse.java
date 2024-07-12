import java.util.Arrays;

class Solution {
    public String solution(String s) {
        String answer = "";
        char[] arr = s.toCharArray();

        Arrays.sort(arr);

        for(int i=0; i<s.length(); i++) {
            answer += arr[s.length() -1-i];
        }

        return answer;
    }
}