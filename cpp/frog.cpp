// 우물 안 개구리
// https://softeer.ai/practice/6289

#include<iostream>
#include <vector>
#include <map>


using namespace std;

void print(map<int, vector<int>> relation)
{
    cout << "Relation:\n";
    for(auto r : relation) {
        cout << "A:" << r.first << endl;
        vector<int> friends = r.second;
        cout << "friends: " ;
        for (int f : friends)
            cout << f << ' ';
        cout << endl;
    }
    cout << "Done:\n";
}
int main(int argc, char** argv)
{
    int N, M;
    cin >> N >> M;

    vector<int> weight;
    for (int i=0; i<N; i++) {
        int w;
        cin >> w;
        weight.push_back(w);
    }

    map<int, vector<int>> relation;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        
        if (relation.find(a) != relation.end()) {
            relation[a].push_back(b);       
        } else {
            relation.insert(make_pair(a, vector<int>{b}));
        }

        if (relation.find(b) != relation.end()) {
            relation[b].push_back(a);       
        } else {
            relation.insert(make_pair(b, vector<int>{a}));
        }        

    }
    //print(relation);

    int best_count = 0;
    for(auto r : relation) {
        int A = r.first;
        vector<int> friends = r.second;

        bool is_best = true;
        for (int B : friends) {
            //cout << "A:" << A << " " << "B:" << B << endl;
            if (weight[A-1] <= weight[B-1]) {
                is_best = false;
                break;
            }
        }
        if (is_best) {
            best_count ++;
        }
    }

    for (int i=0; i<N; i++) {
        if (relation.find(i+1) == relation.end()) {
            best_count ++;
        }
    }
    cout << best_count;

    return 0;
}