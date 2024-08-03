#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string manual;
    getline(cin, manual);

    string secret_order;
    getline(cin, secret_order);
        
    string user_input;
    getline(cin, user_input);
    
    int pos = user_input.find(secret_order);
    if (pos < 0) {
        cout << "normal";
    } else {
        cout << "secret";
    }   
    return 0;
}