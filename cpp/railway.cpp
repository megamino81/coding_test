#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    
    vector<pair<int, int>> stations;

    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;

        stations.push_back({x, y});
    }

    int y = 1001;
    int x;
    for (auto &s : stations) {
        if (y > s.second) {
            x = s.first;
            y = s.second;
        }
    }
    cout << x << " " << y;
    return 0;
}