// 지도 자동 구축
// https://softeer.ai/practice/6280

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n; 
    cin >> n;

    int dots_per_row = 2;
    int total_dots = 4;

    for (int i=0; i<n; i++) {
        // 2 > 3 > 5 > 9 ...
        dots_per_row = dots_per_row + (dots_per_row - 1);
        total_dots = dots_per_row * dots_per_row;

    }
    cout << total_dots;

    return 0;
}