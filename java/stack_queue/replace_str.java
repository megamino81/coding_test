import java.util.*;

class Solution {
    public int solution(String s, String t) {
        int count = 0;
        while(s.contains(t)) {
            count ++;
            s = s.replace(t, "");
        }
        return count;
    }
}