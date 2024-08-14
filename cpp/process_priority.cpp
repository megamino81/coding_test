// 프로세스
// https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=cpp

/*
입력:
2, 1, 3, 2
1
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> indexer;

    for (int i=0; i<priorities.size(); i++) {
        indexer.push_back(i);
    }

    while(!priorities.empty()) {
        int p = priorities[0];
        int max_prior = *max_element(priorities.begin(), priorities.end());
        int i = indexer[0];
        
        priorities.erase(priorities.begin());
        indexer.erase(indexer.begin());

        if (p == max_prior) {
            answer ++;
            if (i == location) {
                break;
            }
        } else {
            priorities.push_back(p);
            indexer.push_back(i);
        }
    }
    return answer;
}

int main(int argc, char** argv)
{
    vector<int> p1 = {2,1,3,2};
    vector<int> p2 = {1,1,9,1,1,1};

    cout << solution(p1, 2) << endl;
    cout << solution(p2, 0) << endl;
    return 0;
}