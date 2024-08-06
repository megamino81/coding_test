// 위험한 효도
// https://softeer.ai/practice/7368

#include <iostream>

using namespace std;

int calc(int a, int b, int d) {
    int cnt = 0;
    bool isBack = true;

    while (d > 0) {
        if (isBack) {
            for (int i=0; i<a; i++) {
                d -= 1;
                cnt += 1;
                if (d == 0) {
                    return cnt;
                }               
            }
        } else {
            cnt += b;
        }
        isBack = !isBack;
    }
    return cnt;
}

int main(int argc, char **argv)
{
    int a, b, d;
    cin >> a >> b >> d;

    int t = calc(a, b, d);
    t += calc(b, a, d);
    cout << t;

   return 0;
}