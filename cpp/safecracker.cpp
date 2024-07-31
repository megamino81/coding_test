#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b) {
    return a.second > b.second;
}

int main(int argc, char** argv)
{
    int answer=0, cur_weight=0;
    vector<pair<int,int>>bag;
    int w, n, m, p;
    
    cin>>w>>n;
    // 배낭 무게, 금속 종류, 각 금속 별 보유 무게와 무게 1당 가격 입력
    
    for(int i=0;i<n;i++) {
        cin >> m >> p;
        bag.push_back(make_pair(m, p));
    }
    // 결국 비싼 금속을 최대한 담고 남은 공간은 그 다음으로 비싼 금속을 담을 수 있을 때 까지 자르면 된다.
    // 입력 예시 1 -> 무게 당 2원 금속을 70만큼 담은 후 무게 당 1원 금속을 30만큼 담으면 총 140+30 = 170의 가격을 담을 수 있다.

    // 금속의 값 어치 순으로 정렬하기
    sort(bag.begin(), bag.end(), cmp);

    // bag의 앞에서 부터 담을 수 있을만큼 담기

    for(auto p:bag){
        while(cur_weight < w){
            if(p.first != 0) {
                cur_weight++;
                p.first--;
                answer += p.second;
            }
            else {
                break;
            }
        }
    }
    cout << answer;
    return 0;
}