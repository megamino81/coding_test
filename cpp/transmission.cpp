// 8단 변속기
// https://softeer.ai/practice/6283

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int gears[8];
    for (int i=0; i<8; i++) {
        cin >> gears[i];
    }

    bool is_ascending = true;
    bool is_mixed = false;
    for (int i=0; i<7; i++) {
        int delta = gears[i+1] - gears[i];
        if (delta != 1) {
            is_ascending = false;
            if (abs(delta) > 1) {
                is_mixed = true;
            }
        }
    }

    if (is_ascending) {
        cout << "ascending";
    } else {
        if (is_mixed) {
            cout << "mixed";
        } else {
            cout << "descending";
        }
    }

    return 0;
}