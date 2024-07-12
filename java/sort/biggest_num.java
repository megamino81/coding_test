import java.util.Arrays;
import java.util.Comparator;

// String으로 바꾸어서
// s1+s2 랑 s2+s1이랑 비교
class Solution {
    public String solution(String[] numbers) {
        String[] nums = new String[numbers.length];
        for (int i=0; i<nums.length; i++) {
            num[i] = numbers[i] + "";
        }
        
        Arrays.sort(nums, new Comparator<String>() {
            public int compare(String o1, String o2) {
                return (o1 + o2).compareTo(o2 + o1);
            }
        });
        
        String answer = "";
        for (int i=0; i<numbers.length; i++) {
            answer += nums[i];
        }
        return answer.charAt(0) == '0' ? "0" : answer;
    }
}