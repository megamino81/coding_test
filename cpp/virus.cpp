// 바이러스
// https://softeer.ai/practice/6284

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    long long k, p;
    int n;
    cin >> k >> p >> n;

    for (int i=0; i<n; i++) {
        k = (k * p) % 1000000007;
    }
    cout << k;
    return 0;
}