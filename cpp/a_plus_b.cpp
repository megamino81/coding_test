#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
    int n;
    int a,b;
    
    cin >> n;   
    for(int i=0; i<n; i++){
        cin >> a >> b;
        cout <<"Case #"<<i+1<<": "<<a+b << "\n";
    }

   return 0;
}
