// 단어변환
// https://school.programmers.co.kr/learn/courses/30/lessons/43163?language=cpp

#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[50];

bool possible(string a, string b)
{
    int cnt = 0;
    for (int i=0; i<a.size(); i++) {
        if (a[i] != b[i]) cnt ++;
    }
    if (cnt == 1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    queue<pair<string, int>> Q;

    Q.push(make_pair(begin,0));

    while (!Q.empty()) {
        string temp = Q.front().first;
        int num = Q.front().second;
        Q.pop();

        if (temp.compare(target) == 0) {
            answer = num;
            break;
        }

        for (int i=0; i<words.size(); i++) {
            if (visited[i]) continue;
            if (possible(temp, words[i])) {
                visited[i] = i;
                Q.push(make_pair(words[i], num+1));
            }
        }
    }
    return answer;
}