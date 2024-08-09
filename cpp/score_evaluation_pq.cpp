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

/*
priority_queue : 
    큐에 있는 모든 원소 중에서 가장 큰 값이 Top을 유지
    push() : 우선순위 큐에 원소를 추가한다
    pop()  : 우선순위 큐에서 top의 원소를 제거한다
    top() : 우선순위 큐에서 top에 있는 원소, 즉 우선순위가 높은 원소를 반환한다.
    empty() : 우선순위 큐가 비어있으면 true를 반환하고 그렇지 않으면 false를 반환한다
    size() : 우선순위 큐에 포함되어 있는 원소의 수를 반환한다
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define maxN 100000 + 10

// 각 참가자별 점수
struct Participant {
	int score1;
	int score2;
	int score3;
};

Participant participants[maxN];
int result[4][maxN];

struct pqNode {
	int id, score;
	pqNode(int i, int s) {
		id = i, score = s;
	}
};

struct comp {
	bool operator()(pqNode a, pqNode b) {
		if (a.score >= b.score) {
			return false;
		} 
		return true;
	}
};

void calculate(priority_queue<pqNode, vector<pqNode>, comp> pq, int i) {
	int rank = 1;
	int prev_rank = 1;
	int prev_score = -1;
	

	while (!pq.empty()) {
		int score = pq.top().score;
		int id = pq.top().id;

		if (prev_score == score) { // 동점일 경우
			result[i][id - 1] = prev_rank;
		}
		else {
			result[i][id - 1] = rank;
			prev_rank = rank;
		}
		rank ++;
		prev_score = score;
		pq.pop();
	}
}

int main(int argc, char** argv)
{
	int N;
	cin >> N;

	priority_queue<pqNode, vector<pqNode>, comp> pqCompetition1, pqCompetition2, pqCompetition3, pqTotal;
	
    for (int i = 1; i <= N; i++) {
		cin >> participants[i].score1;
		pqCompetition1.push(pqNode(i, participants[i].score1));
	}

	for (int i = 1; i <= N; i++) {
		cin >> participants[i].score2;
		pqCompetition2.push(pqNode(i, participants[i].score2));
	}

	for (int i = 1; i <= N; i++) {
		cin >> participants[i].score3;
		pqCompetition3.push(pqNode(i, participants[i].score3));
	}

	for (int i = 1; i <= N; i++) {
		pqTotal.push(pqNode(i, participants[i].score1 + participants[i].score2 + participants[i].score3));
	}



	calculate(pqCompetition1, 0);
	calculate(pqCompetition2, 1);
	calculate(pqCompetition3, 2);
	calculate(pqTotal, 3);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
}
