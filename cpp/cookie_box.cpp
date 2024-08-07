/*
N 박스수
M 팀원수
쿠키수가 팀원수의 배수가 되는 가장 많은 연속된 박스수
*/

/*
입력
N M
박스당쿠키수 ...

5 4
1 2 3 4 5

5 2
1 5 7 10 16
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N, M;
    cin >> N >> M;
    
    vector<int> cookie;
    for (int i=0; i<N; i++) {
        int c;
        cin >> c;
        cookie.push_back(c);
    }

    int max_box = 0;
    for (int i=0; i<N; i++) {
        int sum = 0;
        int count = 0;
        for (int j=i; j<N; j++) {
            sum += cookie[j];
            cout << "i:" << i << " j:" << j << " sum:" << sum << endl;
            if (sum % M == 0) {
                count = j - i + 1;
                cout << "OK, count=" << count << endl;
                max_box = max(max_box, count);
            }
        }
    }
    cout << max_box;
    return 0;
}
