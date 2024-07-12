class Solution {
    public int answer; // 최대 던전 수
    public boolean[] visited; // 방문 여부

    public int solution(int k, int[][] dungeons) {
        // dungeons 배열의 길이만큼 방문 여부 배열 선언
        visited = new boolean[dungeons.length];

        // dfs 메서드 호출
        dfs(0, k, dungeons);

        return answer;
    }

    public void dfs(int depth, int k, int[][] dungeons) {
        for (int i = 0; i < dungeons.length; i++) {
            // 방문하지 않은 상태면서 k가 최소 필요 피로도보다 크거나 같은 경우
            if (!visited[i] && dungeons[i][0] <= k) {
                visited[i] = true; // 방문 처리
                dfs(depth + 1, k - dungeons[i][1], dungeons); // 재귀 호출
                visited[i] = false; // 방문 초기화, 방문여부를 다시 0으로 만드는 이유는 이전 회차의 방문여부가 다음 회차에 영향을 주게 하지 않기 위함
            }
        }

        answer = Math.max(answer, depth);
    }
}
