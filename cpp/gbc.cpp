// GBC
// https://softeer.ai/practice/6270

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int N, M;

    cin >> N >> M;
    vector<int> a, b;

    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        for (int j=0; j<x; j++) {
            a.push_back(y);
        }        
    }

    for (int i=0; i<M; i++) {
        int x, y;
        cin >> x >> y;
        for (int j=0; j<x; j++) {
            b.push_back(y);
        }        
    }

    int over_speed = 0;
    for (int i=0; i<100; i++) {
        over_speed = max(over_speed, b[i] - a[i]);
    }
    cout << over_speed;
    return 0;
}