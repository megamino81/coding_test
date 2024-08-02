// X marks the Spot
// https://softeer.ai/practice/7703

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;
    string result = "";
    for (int i=0; i<n; i++) {
        string s, t;
        cin >> s >> t;
        int pos = s.find('x');
        if (pos < 0) {
            pos = s.find('X');
        }
        result += char(toupper(t[pos]));
    }
    cout << result;
    return 0;
}