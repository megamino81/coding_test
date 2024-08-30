// 체육복
// https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int student[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    for(int i : reserve) student[i] += 1;
    
    for(int i : lost) student[i] -= 1;
    
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}


int main(int argc, char** argv)
{
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};

    cout << solution(5, lost, reserve);
    return 0;
}