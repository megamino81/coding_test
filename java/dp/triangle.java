
import java.util.Arrays;

class Solution {
    private int[][] mem = new int[501][501];
    private int max(int x, int y, int[][] triangle) {
        if (y == triangle.length) return 0;

        if (mem[x][y] != -1) return mem[x][y];

        mem[x][y] = triangle[y][x] + Math.max(
                                    max(x, y +1, triangle),
                                    max(x+1, y+1, triangle));
        return mem[x][y];
    }
    public int solution(int[][] triangle) {
        int answer = 0;
        for (int[] row : mem) {
            Arrays.fill(row, -1);    
        }

        answer = max(0, 0, triangle);
        return answer;
    }
}
