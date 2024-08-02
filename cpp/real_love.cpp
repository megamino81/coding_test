// 진정한 효도
// https://softeer.ai/practice/7374

#include <iostream>
#include <vector>

using namespace std;

int calcCost(int a, int b, int c)
{
    int min_value = min(a, b);
    min_value = min(min_value, c);
    int max_value = max(a, b);
    max_value = max(max_value, c);

    int mid = a + b + c - min_value - max_value;
    return abs(mid - a) + abs(mid - b) + abs(mid - c);
}

int main(int argc, char** argv)
{
    vector<vector<int>> map = vector<vector<int>>(3, vector<int>(3, 0));
    int cost = INT32_MAX;

    for (int i=0; i<3; i++) {
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    }

    for (int i=0; i<3; i++) {
        int a, b, c;
        a = map[i][0];
        b = map[i][1];
        c = map[i][2];
        if (a == b && a == c) {
            cout << 0;
            return 0;
        }   
        int tmp = calcCost(a, b, c);
        cost = min(cost, tmp);

    }

    for (int i=0; i<3; i++) {
        int a, b, c;
        a = map[0][i];
        b = map[1][i];
        c = map[2][i];
        if (a == b && a == c) {
            cout << 0;
            return 0;
        }   
        int tmp = calcCost(a, b, c);
        cost = min(cost, tmp);
    }
    cout << cost;

    return 0;
}
