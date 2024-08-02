// 신기한 소수 찾기
// (백준 2023)


/*
N(자릿수)
DFS 실행 (2 3 5 7을 시작 수로 정함)

// DFS 구현
DFS(숫자, 현재 자릿수) {
    if (자릿수 == N) {
        if (소수이면) 수 출력
        탐색 종료
    }
    for (1 ~ 9반복) {
        if (뒤에 붙는 수가 홀수이면서 소수인 경우)
            DFS(수 * 10, 현재 자릿수 + 1)
    }
}

// 소수 구하기 함수
for (2 ~ 현재수/2까지 반복) {
    if (i로 나눈 나머지가 0이면)
        return 소수 아님
}
return 소수 맞음
*/


#include <iostream>

using namespace std;

static int N;
bool isPrime(int number);
void DFS(int number, int jarisu);

int main(int argc, char **argv)
{
    cin >> N;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    return 0;
}

void DFS(int number, int jarisu)
{
    if (jarisu == N) {
        if (isPrime(number)) {
            cout << number << "\n";
        }
        return;
    }

    for (int i=1; i<10; i++) {
        if (i%2 == 0) {
            continue;
        }
        if (isPrime(number * 10 + i)) {
            DFS(number * 10 + i, jarisu + 1);
        }
    }
}

bool isPrime(int number)
{
    for(int i=2; i<=number/2; i++) {
        if (number%i == 0)
            return false;
    }
    return true;
}