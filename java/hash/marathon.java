import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {

        HashMap<String, Integer> hm = new HashMap<>();

        for (String player : participant)
            hm.put(player, hm.getOrDefault(player, 0) + 1);

        for (String player : completion) {
            int c = hm.get(player) - 1;
            hm.put(player, c);
            if (c == 0)
                hm.remove(player);
        }

        /*
        String answer = "";
        for (String key : hm.keySet()) {
            if (hm.get(key) != 0){
                answer = key;
            }
        }
        return answer;
        */
        return hm.keySet().iterator().next();
    }
}