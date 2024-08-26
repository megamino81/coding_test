// 소수찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=cpp

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
bool visited[10];
set<int> numberSet;


bool isPrime(int number)
{
    if (number == 0 || number == 1) {
        return false;
    }

    for(int i=2; i<=number/2; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}


bool compare(char a, char b)
{
    return a > b;
}

int solution(string numbers) {
    int answer = 0;

    set<int> primeSet;

    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i=0; i < numbers.size(); i++)
        {
            string sub = numbers.substr(0, i+1);
            int subNum = stoi(sub);
            cout << sub <<  endl;
            if (isPrime(subNum)) {
                cout << subNum << " is prime!\n";;
                primeSet.insert(subNum);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = primeSet.size();
    return answer;
}


int main(int argc, char** argv)
{
    string numbers = "17";
    string numbers2 = "011";

    cout << solution(numbers) << endl;
    cout << solution(numbers2) << endl;

    return 0;
}