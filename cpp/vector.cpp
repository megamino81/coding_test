#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

    vector<int> A;
    A.push_back(1);
    A.insert(A.begin(), 7);

    return 0;
}