#include<iostream>
#include<string>
using namespace std;

int calculateStringToMin(string s) {
	int hour = stoi(s.substr(0, 2));
	int min = stoi(s.substr(3, 2));
	return hour * 60 + min;
}

int main(int argc, char** argv)
{
	int b = 1;
	int result = 0;
	for (int i = 0; i < 5; i++) {
		string start, end;
		cin >> start >> end;
		int start_min = calculateStringToMin(start);
		int end_min = calculateStringToMin(end);
		result += end_min - start_min;
	}
	cout << result;
	return 0;
}