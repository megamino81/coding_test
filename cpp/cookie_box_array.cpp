
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> cookie(N);
    for (int i = 0; i < N; i++) {
        cin >> cookie[i];
    }

    vector<int> modIndex(M, -1);  // 나머지를 인덱싱하기 위한 배열, -1로 초기화
    modIndex[0] = -1;  // 초기 조건 설정 (sum이 0인 경우)

    int sum = 0;
    int max_len = 0;

    for (int i = 0; i < N; i++) {
        sum += cookie[i];
        int mod = sum % M;

        if (modIndex[mod] != -1) {
            // 만약 두 인덱스 i, j에서 나머지가 같으면 sum[j] - sum[i]는 M의 배수가 된다
            int previousIndex = modIndex[mod];
            max_len = max(max_len, i - previousIndex);
        } else {
            modIndex[mod] = i;
        }
    }

    cout << max_len;
    return 0;
}