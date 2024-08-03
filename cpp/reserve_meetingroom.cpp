// 회의실 예약
// https://softeer.ai/practice/6266

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
    int N, M;
    map<string,vector<int>> rooms;
    vector<string> room_names;

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string name;
        cin >> name;
        room_names.push_back(name);
        rooms.insert({name, vector<int>(9, 0)});
    }

    for (int i=0; i<M; i++) {
        string name;
        int start, end;
        cin >> name >> start >> end;
        vector<int>& room = rooms[name];

        start = start - 9;
        end = end - 9;
        
        for (int j=start; j<end; j++) {
            room[j] = 1;
        }
    }

    sort(room_names.begin(), room_names.end());

    int count_for_line = 0;

    for (string name : room_names) {
        vector<int> room = rooms[name];

        cout << "Room " << name << ":\n";

        vector<string> slots;
        int count = 0;
        int start = -1;
        int end = -1;
        vector<pair<int, int>> times;
        for (int i=0; i<9; i++) {
            int v = room[i];
            if (v == 0) {
                if (start == -1) {
                    start = i;
                    end = i;
                }
                if (i == 8) {
                    end = 9;
                    times.push_back(make_pair(start, end));
                    count ++;
                }
            } else {
                end = i;
                if (start != -1 && end != -1 && start <= end) {
                    times.push_back(make_pair(start, end));
                    start = -1;
                    end = -1;
                    count ++;
                }
            }
        }
        
        if (count == 0) {
            cout << "Not available" << "\n";
        } else {
            cout << count << " available:\n";
            int c = 0;
            for (auto t: times) {
                int start = t.first + 9;
                int end = t.second + 9;

                cout << setw(2) << std::setfill('0') << start << '-' << end << "\n";
            }
        }
        count_for_line ++;
        if (count_for_line < N) {
            cout << "-----" << "\n";
        }
    }
    return 0;
}

