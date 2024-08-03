// 성적 평균
// https://softeer.ai/practice/6294

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
    int N, K;
    cin >> N >> K;
    vector<int> score;
    vector<pair<int,int>> slots;

    for (int i=0; i<N; i++) {
        int s;
        cin >> s;
        score.push_back(s);
    }

    for (int i=0; i<K; i++) {
        int start, end;
        cin >> start >> end;
        slots.push_back({start, end});
    }

    for (auto slot : slots) {
        int start = slot.first;
        int end = slot.second;

        double total = 0;
        for(int i=start-1; i<end; i++) {
            total += score[i];
        }

        double avg = total / (end - start + 1);

        cout << fixed << setprecision(2) << avg << endl;
    }
    return 0;
}