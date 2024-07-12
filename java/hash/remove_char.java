import java.util.HashSet;
import java.util.Set;

class _Solution {
    public String solution(String my_string) {
        String answer = "";

        for (int i=0; i<my_string.length(); i++) {
            char c = my_string.charAt(i);
            if (answer.contains(c + "")) continue;
            answer += c;
        }
        return answer;
    }
}

class Solution {
    public String solution(String my_string) {
        Set<Character> used = new HashSet<>();
        StringBuilder builder = new StringBuilder();
        for (char c : my_string.toCharArray()) {
            if (used.contains(c)) continue;
            used.add(c);
            builder.append(c);
        }
        return builder.toString();
    }
}