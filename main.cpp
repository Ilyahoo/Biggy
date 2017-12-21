#include <iostream>
#include "bigint.h"
#include <exception>
using namespace std;

int main()
{   BigInt a1;
    cin >> a1;
    vector<int> lets_see;
    lets_see = a1.GetNumber();
    for(vector<int>::reverse_iterator it = lets_see.rbegin(); it != lets_see.rend(); it++){
        cout << *it;
    }
    cout << "Hello world!" << endl;
    return 0;
}
