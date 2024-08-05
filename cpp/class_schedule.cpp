// 강의실 배정
// https://softeer.ai/practice/6291

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    
    vector<pair<int,int>> schedule;

    for(int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        schedule.push_back({e, s});
    }
    sort(schedule.begin(), schedule.end());

    int count = 1;
    int now = schedule[0].first;
    for(int i=1; i<N; i++) {
        int start, end;
        start = schedule[i].second;
        end = schedule[i].first;
        if (now <= start) {
            count ++;
            now = end;
        }
    }
    cout << count;
   return 0;
}