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
    // 종료시간과 시작시간을 바꾸어 push
    // 종료시간 sort, 그 안에서 시작시간 sort됨
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