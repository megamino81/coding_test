import java.util.*;

public class Solution {
    public int solution(String numbers) {
        int answer = 0;
        HashSet<Integer> primeSet = new HashSet<>();

        // 종이 조각으로 만들 수 있는 모든 수 조합 생성
        List<String> combinations = new ArrayList<>();
        for (int i = 1; i <= numbers.length(); i++) {
            permutation(numbers.toCharArray(), 0, i, combinations);
        }

        // 조합별로 소수인지 판별
        for (String combination : combinations) {
            int num = Integer.parseInt(combination);
            if (isPrime(num) && !primeSet.contains(num)) {
                primeSet.add(num);
                answer++;
            }
        }

        return answer;
    }

    // 순열을 통해 가능한 모든 조합 생성
    private void permutation(char[] arr, int depth, int r, List<String> combinations) {
        if (depth == r) {
            combinations.add(new String(arr, 0, r));
            return;
        }

        for (int i = depth; i < arr.length; i++) {
            swap(arr, depth, i);
            permutation(arr, depth + 1, r, combinations);
            swap(arr, depth, i);
        }
    }

    private void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // 소수 판별
    private boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;

        //for (int i = 3; i * i <= num; i += 2) {
        for (int i = 3; i <= (int)Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }

        return true;
    }
}
