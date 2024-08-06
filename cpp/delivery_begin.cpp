// 연탄 배달의 시작
// https://softeer.ai/practice/7626
    
#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    vector<int> list;
    map<int, int> m;
    for (int i=0; i<n; i++) {
        int d;
        cin >> d;
        list.push_back(d);
    }

    for (int i=1; i<list.size(); i++) {
        int min = list[i] - list[i-1];
        m[min] += 1;
    }

    int min = INT_MAX;
    for (const auto& pair : m) {
        if (pair.first < min) {
            min = pair.first;
        }
    }
    cout << m[min];
    return 0;
}