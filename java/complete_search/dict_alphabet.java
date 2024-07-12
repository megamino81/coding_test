/*
1   A
2   AA
3   AAA
4   AAAA
5   AAAAA
6   AAAAE
7   AAAAU
   .
10  AAAE
11  AAAEA
   .
16  AAAI
   .
22  AAAO
   .
28  AAAU
   .
34  AAE
마지막 자리면 문자가 바뀔 때마다 1씩 증가하고, 4번째 자리인 경우는 6씩 증가하고, 3번째 자리인 경우는 31씩 증가하는 것을 볼 수 있다.

x 가 0이 아닐 때 : f(x) = f(x - 1) + 5^x

f(0) = 1
f(1) = 1 + 5^1 = 6
f(2) = 6 + 5^2 = 31
f(3) = 31 + 5^3 = 156
f(4) = 156 + 5^4 = 781
*/

import java.util.ArrayList;
import java.util.List;

public class Solution1 {
    public int solution(String word) {
        int answer = 0;
        int[] order = {781, 156, 31, 6, 1}; // 각 자릿수 별 단어의 순서를 나타내는 배열

        // 주어진 단어에 대해 각 자릿수 별로 순서를 계산하여 더함
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            int idx = "AEIOU".indexOf(ch); // 해당 알파벳의 인덱스를 찾음
            System.out.println(idx);
            answer += idx * order[i] + 1; // 해당 알파벳의 인덱스와 순서를 곱한 후 더함
        }

        return answer;
    }
}



class Solution {
    static String[] arr;
    static List<String> list;
    public int solution(String word) {
        int answer = 0;

        list = new ArrayList<>();
        arr = new String[]{"A", "E", "I", "O", "U"};

        dfs(word, "", 0);

        for (int i = 0; i < list.size(); i++) {
            if(list.get(i).equals(word)) {
                answer = i;
                break;
            }
        }
        return answer;
    }

    static void dfs(String word, String str, int depth) {
        list.add(str);

        if(depth == 5) {
            return;
        }

        for (int i = 0; i < arr.length; i++) {
            dfs(word, str + arr[i], depth + 1);
        }
    }
}