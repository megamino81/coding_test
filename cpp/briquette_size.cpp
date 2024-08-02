// 연탄의 크기
// https://softeer.ai/practice/7628

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;

    vector<int> list;
    for (int i=0; i<n; i++) {
        int v;
        cin >> v;
        list.push_back(v);
    }

    sort(list.begin(), list.end());

    int result = 0;
    int count = 0;
    for (int i=2; i<=100; i++) {
        count = 0;
        for (int j=0; j<n; j++) {
            if (list[j] % i == 0) {
                count ++;
            }
            if (result < count)
                result = count;
        }
    }

    cout << result;

    return 0;
}