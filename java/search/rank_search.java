import java.util.*;

class Solution {
    public int[] solution(String[] info, String[] query) {
        // 1. info를 기반으로 hashMap 만들기
        HashMap<String, ArrayList<Integer>> hashMap = new HashMap<>();

        for (String i : info) {
            String[] data = i.split(" ");
            String[] languages = { data[0], "-" };
            String[] jobs = { data[1], "-" };
            String[] exps = { data[2], "-" };
            String[] foods = { data[3], "-" };
            Integer value = Integer.parseInt(data[4]);

            for (String lang : languages)
                for (String job : jobs)
                    for (String exp : exps)
                        for (String food : foods) {
                            // key: java backend juninor pizza
                            // value: 150
                            // key: - - - - 
                            // value: 150
                            String[] keyData = { lang, job, exp, food };
                            String key = String.join(" ", keyData);
                            ArrayList<Integer> arr = hashMap.getOrDefault(key, new ArrayList<Integer>());

                            arr.add(value);
                            hashMap.put(key, arr);
                        }
        }
        /*
        python - - chicken = [210, 150, 50]
        ...
        - - - - = [150, 210, 150, 260, 80, 50]
        */
        //System.out.println(hashMap);

        // 2. 각 hashMap의 value를 오름차순 정렬하기
        for (ArrayList<Integer> scoreList : hashMap.values())
            //scoreList.sort(null);
            Collections.sort(scoreList);

        // 3. query 조건에 맞는 지원자를 가져오기
        int[] answer = new int[query.length];
        int i = 0;
        for (String q : query) {
            String[] data = q.split(" and ");
            //["java", "backend", "junior", "pizza 100"]

            int target = Integer.parseInt(data[3].split(" ")[1]);
            data[3] = data[3].split(" ")[0];
            String key = String.join(" ", data);

            if (hashMap.containsKey(key)) {
                ArrayList<Integer> list = hashMap.get(key);

                // 4. lower-bound/하한선 찾기
                // BinarySearch
                int left = 0;
                int right = list.size();
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (list.get(mid) >= target)
                        right = mid;
                    else
                        left = mid + 1;
                }

                answer[i] = list.size() - left;
            }
            i++;
        }
        return answer;
    }
}