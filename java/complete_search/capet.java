/*
구하는 답을 [x, y] 라고 하면,
x와 y사이의 관계식

2x+2y-4=brown
(x-2)(y-2)=yellow

*/
class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];

        int size = brown + yellow;
        for (int w=1; w<=size; w++) {
            if (size % w != 0) {
                continue;
            }
            int h = size / w;

            if ((w-2) * (h-2) == yellow) {
                answer[0] = Math.max(w, h);
                answer[1] = Math.min(w, h);
                break;
            }
        }
        return answer;
    }
}