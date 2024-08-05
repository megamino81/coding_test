// 포켓몬
// https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=cpp

 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;

 void print(vector<int> nums)
 {
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
 }

 int main(int argc, char** argv)
 {
    int n;
    cin >> n;

    vector<int> nums;
    for(int i=0; i<n; i++) {
        int p;
        cin >> p; 
        nums.push_back(p);
    }

    int answer = 0;
    answer = nums.size() / 2;

    sort(nums.begin(), nums.end());
    //print(nums);
    nums.erase(
        unique(nums.begin(), nums.end()), 
        nums.end());
    //print(nums);

    if (answer > nums.size())
        answer = nums.size();
    return 0;
 }