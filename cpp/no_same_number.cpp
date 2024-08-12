// 같은 숫자는 싫어
// https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=cpp

#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prev_num = -1;
    for(int a : arr) {
        if (a != prev_num) {
            answer.push_back(a);
            prev_num = a;
        }
    }
    return answer;
}

vector<int> solution2(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

int main(int argc, char** argv)
{
    vector<int> num_list = {
      1, 1, 3, 3, 0, 1, 1  
    };
    solution(num_list);

    cout << endl;

    vector<int> num_list1 = {
      4, 4, 4, 3, 3  
    };
    solution(num_list1);
    return 0;
}