// K번째수
// https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    int start, end, pos;
    for (int i=0; i<commands.size(); i++) {
        vector<int> comm = commands[i];
        start = comm[0];
        end = comm[1];
        pos = comm[2];
        vector<int> sub_array;
        for (int j=start-1; j<=end-1; j++) {
            sub_array.push_back(array[j]);
        }
        sort(sub_array.begin(), sub_array.end());
        answer.push_back(sub_array[pos-1]);
    }

    return answer;
}

int main(int argc, char** argv)
{
    vector<int> a = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> comm = {
        {2,5,3},
        {4,4,1},
        {1,7,3}
    };

    vector<int> answer = solution(a, comm);
    for(int i:answer) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
