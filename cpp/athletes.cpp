// 완주하지 못한 선수
// https://school.programmers.co.kr/learn/courses/30/lessons/42576?language=cpp

#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> strMap;
    for(auto elem : completion)
    {
        if(strMap.end() == strMap.find(elem))
            strMap.insert(make_pair(elem, 1));
        else
            strMap[elem]++;
    }

    for(auto elem : participant)
    {
        if(strMap.end() == strMap.find(elem))
        {
            answer = elem;
            break;
        }
        else
        {
            strMap[elem]--;
            if(strMap[elem] < 0)
            {
                answer = elem;
                break;
            }
        }
    }
    return answer;
}


vector<string> split(string str, char delimiter)
{
    istringstream iss(str);
    string buffer;

    vector<string> result;
    while (getline(iss, buffer, delimiter)) {
        result.push_back(buffer);
    }
    return result;
}

void print(vector<string> l)
{
    for(int i=0; i<l.size(); i++) {
        cout << l[i] << ' ';
    }
    cout << endl;
}
int main(int argc, char** argv)
{
    vector<string> participant;
    vector<string> completion;

    string str;
    getline(cin, str);
    participant = split(str, ' ');
    getline(cin, str);
    completion = split(str, ' ');

    //print(participant);
    //print(completion);

    cout << solution(participant, completion);
    return 0;
}

