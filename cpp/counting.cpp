
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int _main(int argc, char **argv)
{
    int T;
    cin >> T;

    int arr[2];

    for(int i=0; i<T; i++) {
        cin >> arr[i];
    }    

    for(int i=0; i<T; i++) {
        int n = arr[i];
        int a = n / 5;
        int b = n % 5;
        
        string result;
        for (int j=0; j<a; j++) {
            result += "++++";
        }
        for (int j=0; j<b; j++) {
            result += "|";
        }
        cout << result;
    }

    return 0;
}


int main(int argc, char** argv)
{
    int t;
    cin >> t;

    vector<string> results;

    for (int i = 0; i < t; i++)
    {
        int in;
        cin >> in;

        int div = in / 5;
        int cut = in % 5;

        string result;
        for (int i = 0; i < div; i++)
        {
            result += "++++ ";
        }

        for (int i = 0; i < cut; i++)
        {
            result +="|";
        }
        results.push_back(result+"\n");
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i];

    }
    return 0;
}