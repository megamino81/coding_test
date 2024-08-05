// 징검다리
// https://softeer.ai/practice/6293

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    // N의 최대가 3x10^3이다. O(N^2)은 9x10^6이다. 약 10^7이므로 0.1초 걸린다. 
    int n, high, answer=1;
    vector<int> v;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> high;
        v.push_back(high);
    }

    vector<int> dp(n, 1);

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (v[i] < v[j]) {
                dp[j] = max(dp[i]+1, dp[j]); // 가장 많이 돌을 밟는 경우의 수를 구함
                answer = max(answer, dp[j]);
            }
        }
    }
    cout << answer;
    return 0;
}