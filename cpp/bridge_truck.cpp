// 다리를 지나는 트럭
// https://school.programmers.co.kr/learn/courses/30/lessons/42583?language=cpp

/*
입력:

2
10
7, 4, 5, 6
==> 8

100
100
10
==> 101

100
100
10,10,10,10,10,10,10,10,10,10
==> 110
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int second = 0;

    queue<int> bridgeQ;

    for (int i=0; i<bridge_length; i++) {
        bridgeQ.push(0);
    }

    int cur_weight = 0;
    while (!truck_weights.empty()) {
        second ++;

        cur_weight -= bridgeQ.front();
        bridgeQ.pop();

        int w = truck_weights[0];
        if (cur_weight + w <= weight) {
            truck_weights.erase(truck_weights.begin());
        } else {
            w = 0;
        }
        cur_weight += w;
        bridgeQ.push(w);
    }
    
    return second + bridgeQ.size();
}

int main(int argc, char** argv)
{
    vector<int> truck_weights1 = {7, 4, 5, 6};
    cout << solution(2, 10, truck_weights1) << endl;

    vector<int> truck_weights2 = {10};
    cout << solution(100, 100, truck_weights2) << endl;

    vector<int> truck_weights3 = {10,10,10,10,10,10,10,10,10,10};
    cout << solution(100, 100, truck_weights3) << endl;
    return 0;
}