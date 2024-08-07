/*
최적화 방법
쿠키 수의 연속된 구간 합이 
M의 배수가 되는 가장 긴 구간을 찾기 위해 누적 합과 해시맵을 사용하는 방법으로 최적화할 수 있습니다. 
이는 O(N)의 시간 복잡도로 문제를 해결할 수 있습니다

설명
1. 누적 합 사용: 각 원소를 더하면서 현재까지의 합 sum을 유지합니다.

2. 해시맵 사용: 누적 합을 M으로 나눈 나머지를 키로, 해당 나머지가 처음 등장한 인덱스를 값으로 저장합니다.

3. 최대 길이 계산: 동일한 나머지가 다시 등장하면 그 사이의 구간이 M의 배수가 되는 구간입니다. 
   구간 길이를 계산하여 최대 길이를 업데이트합니다.

4. 음수 나머지 보정: 
   C++에서는 음수 나머지가 발생할 수 있으므로, 이를 M을 더해 보정합니다.

이 접근법은 O(N)의 시간 복잡도로 문제를 효율적으로 해결합니다.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


void print_prefix(unordered_map<int, int> prefix)
{
    cout << "PrefixSumIndex:\n";
    for (auto pre : prefix) {
        cout << "key:" << pre.first << " value:" << pre.second << endl;
    }
}
int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<int> cookie(N);
    for (int i = 0; i < N; i++) {
        cin >> cookie[i];
    }

    unordered_map<int, int> prefixSumIndex;
    prefixSumIndex[0] = -1;   // 초기 조건 설정 (sum이 0인 경우)

    int sum = 0;
    int max_len = 0;
    
    for (int i = 0; i < N; i++) {
        sum += cookie[i];
        cout << "i:" << i << " cookie[i]:" << cookie[i] << " sum:" << sum << endl;
        int mod = sum % M;
        cout << "mod:" << mod << endl;
        
        
        // 나머지가 이미 해시맵에 있는 경우
        if (prefixSumIndex.find(mod) != prefixSumIndex.end()) {
            // 만약 두 인덱스 i, j에서 나머지가 같으면 sum[j] - sum[i]는 M의 배수가 된다
            // 현대 인덱스 i와 이전에 같은 나머지를 가진 인덱스 사이의 거리를 구함
            max_len = max(max_len, i - prefixSumIndex[mod]);
        } else {
            prefixSumIndex[mod] = i;
        }

        print_prefix(prefixSumIndex);

        cout << "max_len:" << max_len << endl;
        cout << endl;
    }
    
    cout << max_len;
    return 0;
}
