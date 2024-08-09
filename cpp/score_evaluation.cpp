// 성적 평가
// https://softeer.ai/practice/6250

/*
N 참가자수
대회 3개
나보다 점수가 큰 사람의 수 + 1 = 자신의 등수
최종 등수는 세 대회의 점수의 합

각 참가자의 대회별 등수 및 최종 등수를 출력

제약조건:
    3 <= N <= 100,000

입력:
첫째줄 참가지수 N
이어 세개의 줄에 각 대회의 결과를 나타내는 N개의 정수

3
40 80 70
50 10 20
100 70 30
==> 
3 1 2
1 3 2
1 2 3
1 2 3

3
1000 1000 700
300 100 400
200 400 400
==>
1 1 3
2 3 1
3 1 1
1 1 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compare(int a, int b)
{
    return a > b;
}


void _print_rank(vector<int> score)
{
    vector<int> score_sorted = score;
    sort(score_sorted.begin(), score_sorted.end(), compare);
    
    for (int i=0; i<N; i++) {
        auto it = find(score_sorted.begin(), score_sorted.end(), score[i]);
        cout << it - score_sorted.begin() + 1;
        if (i < N-1) cout << " ";
    }
    cout << "\n";
}

void print_rank(const vector<int>& score)
{
    vector<pair<int, int>> indexed_score(N);
    for (int i = 0; i < N; ++i) {
        indexed_score[i] = {score[i], i};
    }

    sort(indexed_score.rbegin(), indexed_score.rend());

    vector<int> rank(N);
    int cur_rank = 1;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && indexed_score[i].first != indexed_score[i - 1].first) {
            cur_rank = i + 1;
        }
        rank[indexed_score[i].second] = cur_rank;
    }

    for (int i = 0; i < N; ++i) {
        cout << rank[i];
        if (i < N - 1) cout << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv)
{
	cin >> N;

    vector<int> score[3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<N; j++) {
            int s;
            cin >> s;
            score[i].push_back(s);
        }
    }

    vector<int> total(N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<3; j++) {
            total[i] += score[j][i];
        }
    }

    for (int i=0; i<3; i++) {
        print_rank(score[i]);
    }
    print_rank(total);
    
    return 0;
}