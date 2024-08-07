/*
Q: 제품수
제품을 만들때 필요한 설비구간
    s 시작 설비
    e 끝 설비
N:설비수
K: 처분할 설비수
Q개 모두 한번씩 만든후, 가장 많이 사용된 K개 설비 처분, 처분시 설비번호 작은 것부터.

처분후 N-K 설비중(남은 설비중), 가장 많이 사용된 설비 번호?
*/

/*
입력
Q N K
Q1 Q2 Q3 ...
Q1-line 
Q2-line 
Q3-line 
...

5 6 2
3 7 10 13 17 20
1 10
3 9
4 23
12 18
3 15 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main(int argc, char** argv)
{
    int Q, N, K;
    cin >> Q >> N >> K;

    vector<int> device;
    map<int, int> device_used;
    for (int i=0; i<N; i++) {
        int d;
        cin >> d;
        device.push_back(d);
        device_used[d] = 0;
    }

    vector<pair<int,int>> line;
    for (int i=0; i<Q; i++) {
        int s, e;
        cin >> s >> e;
        line.push_back(make_pair(s, e));
    }

    for (auto l : line) {
        int s, e;
        s = l.first;
        e = l.second;
        for (int i=0; i<N; i++) {
            if (device[i] >= s && device[i] <= e) {
                device_used[device[i]] ++;
            }
        }
    }
   
    cout << "device_used:\n";
    for (int i=0; i<N; i++) {
        cout << device[i] << ":" << device_used[device[i]] << endl;
    }
 
    vector<pair<int,int>> list;
    for (int i=0; i<N; i++) {
        list.push_back(make_pair(device[i], device_used[device[i]]));
    }

    sort(list.begin(), list.end(), compare);

    cout << "sorted list:\n";
    for (auto l: list) {
        cout << l.first << ":" << l.second << endl;
    }

    cout << list[K].first;

    return 0;
}