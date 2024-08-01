#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    int *f = new int[N];
    for (int i=0; i<N; i++) {
        cin >> f[i];
    }

    int max_f = -10000000;
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            int mf = f[i] * f[j];
            if (mf > max_f)
                max_f = mf;
        }
    }
    cout << max_f;
    return 0;
}