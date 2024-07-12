

import java.util.*;

/*
[3, 0, 6, 1, 5]	3

[0, 1, 3, 5, 6]

*/

class Solution {
    public int solution(int[] citations) {       
        int h_index = 0;
        Arrays.sort(citations);

        ArrayList<Integer> arr = new ArrayList<Integer>();

        for (int i=0; i<citations.length; i++) {
            arr.add(citations[i]);
        }

        for (int i=0; i<arr.size(); i++) {
            int c = arr.get(arr.size() - 1 - i);
            if (c > h_index) {
                h_index ++;
            }
        }

        return h_index;
    }
}