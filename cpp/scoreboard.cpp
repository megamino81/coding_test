// 전광판
// https://softeer.ai/practice/6268

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    map<string, vector<int>> map;
	map.insert({ "0",{1,1,1,0,1,1,1} });
	map.insert({ "1",{0,0,1,0,0,1,0} });
	map.insert({ "2",{1,0,1,1,1,0,1} });
	map.insert({ "3",{1,0,1,1,0,1,1} });
	map.insert({ "4",{0,1,1,1,0,1,0} });
	map.insert({ "5",{1,1,0,1,0,1,1} });
	map.insert({ "6",{1,1,0,1,1,1,1} });
	map.insert({ "7",{1,1,1,0,0,1,0} });
	map.insert({ "8",{1,1,1,1,1,1,1} });
	map.insert({ "9",{1,1,1,1,0,1,1} });
	map.insert({ " ",{0,0,0,0,0,0,0} });

    int T;
    string A, B;

    cin >> T;
    
    string result;

    for (int i=0; i<T; i++) {
        cin >> A >> B;
        int count = 0;
        int blank_length = 5 - A.size();
        for (int j=0; j<blank_length; j++) {
            A.insert(0, " ");
        }
        blank_length = 5 - B.size();
        for (int j=0; j<blank_length; j++) {
            B.insert(0, " ");
        }

        for (int j=0; j<5; j++) {
            string keyA = A.substr(j, 1);
            string keyB = B.substr(j, 1);

            for (int k=0; k<7; k++) {
                if (map[keyA][k] != map[keyB][k]) {
                    count ++;
                }
            }
        }
        result += to_string(count) + "\n";
    }
    cout << result;
    return 0;
}  