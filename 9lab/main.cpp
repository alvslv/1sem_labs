#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;


int main() {
    short x; cin >> x;
    char* ptr = (char*)&x;

    for (short i = 1; i >= 0; i--)
        cout << (short)ptr[i] << ' ';
    cout << endl;
}