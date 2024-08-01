// https://softeer.ai/practice/9657
// 나무 공격, lv.2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    int n, m;
    cin >> n >> m;
    vector<int> count_list;
    for (int i=0; i<n; i++) {
        int row[8];
        int count_one = 0;
        for (int j=0; j<8; j++) {
            cin >> row[j];
            if (row[j] == 1) {
                count_one ++;
            }
        }
        //cout << count_one << endl;
        count_list.push_back(count_one);
    }

    for (int i=0; i<2; i++) {
        int L, R;
        cin >> L >> R;
        for (int j=L-1; j<R; j++) {
            count_list[j] -= 1;
        }
    }
 
    int total_one = 0;
    for (int i=0; i<n; i++) {
        if (count_list[i] > 0) {
            total_one += count_list[i];
        }
    }

    cout << total_one;

    return 0;
}