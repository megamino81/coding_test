#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delimiter)
{
    istringstream iss(s);
    string buffer;

    vector<string> result;
    while (getline(iss, buffer, delimiter)) {
        result.push_back(buffer);
    }
    return result;
}
int main(int argc, char** argv)
{
    string input_str;
    cin >> input_str;

    vector<string> result = split(input_str, '-');
    for(string s : result) {
        cout << s.at(0);
    }

    return 0;
}