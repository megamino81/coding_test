import java.util.Queue;
import java.util.LinkedList;

class Solution {
    // U, D, L, R
    private int[] dx = {0, 0, -1, 1};
    private int[] dy = {-1, 1, 0, 0};

    private class Position {
        public int x;
        public int y;
        public int count;
        private Position(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }
    }

    public int solution(int[][] maps) {

        boolean[][] visited = new boolean[maps.length][maps[0].length];
        Queue<Position> queue = new LinkedList<>();

        visited[0][0] = true;
        queue.add(new Position(0, 0, 1));


        while (!queue.isEmpty()) {
            Position pos = queue.poll();

            if (pos.x == maps[0].length -1 && pos.y == maps.length - 1) {
                return pos.count;
            }

            for (int i=0; i<dx.length; i++) {
                int nx = pos.x + dx[i];
                int ny = pos.y + dy[i];

                if (nx < 0 || ny < 0 || 
                        nx >= maps[0].length  || ny >= maps.length || maps[ny][nx] == 0) {
                    continue;
                }

                if (visited[ny][nx]) {
                    continue;
                }

                visited[ny][nx] = true;
                queue.add(new Position(nx, ny, pos.count+1));
            }
        }
        return -1;
    }   
}