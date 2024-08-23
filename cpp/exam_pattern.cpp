// 모의고사
// https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=cpp

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    vector<vector<int>> patterns = {
        { 1,2,3,4,5 },
        { 2,1,2,3,2,4,2,5 },
        { 3,3,1,1,2,2,4,4,5,5 }
    };

    vector<int> score(3, 0);

    for (int i=0; i<=answers.size(); i++) {
        int answer = answers[i];
        for (int j=0; j<patterns.size(); j++) {
            vector<int> pattern = patterns[j];
            int pindex = i % pattern.size();
            if (pattern[pindex] == answer) {
                score[j] ++;
            }
        }
    }

    int max_score = *max_element(score.begin(), score.end());

    for (int i=0; i<score.size(); i++) {
        if (score[i] == max_score) {
            answer.push_back(i+1);
        }
    }

    return answer;
}

int main(int argc, char** argv)
{
    vector<int> answers = { 1,2,3,4,5 };
    vector<int> answers2 = { 1,3,2,4,2 };
    vector<int> ret = solution(answers);
    for(int i: ret) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ret2 = solution(answers2);
    for(int i: ret2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}