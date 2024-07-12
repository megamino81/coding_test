
import java.util.Stack;
import java.util.stream.Collectors;

class Solution {
    public String solution(String number, int k) {
        Stack<Character> stack = new Stack<>();
        for (char c : number.toCharArray()) {
            while (k > 0 & !stack.isEmpty() && c > stack.peek()) {
                stack.pop();
                k --;
            }
            stack.push(c);
        }

        while (k-- > 0) {
            stack.pop();
        }
        /*
        String answer = "";
        while (!stack.isEmpty()) {
            answer += stack.pop();
        }
        return new StringBuffer(answer).reverse().toString();
        */

        return stack.stream().map(String::valueOf).collect(Collectors.joining());
    }
}