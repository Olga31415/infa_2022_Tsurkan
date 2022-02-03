#include <iostream>
using namespace std;

int main() {
    int min = INT_MAX;
    int x = 0;
    while(cin >> x) {
        if (x % 101 < min % 101) {
            min = x;
        }
    }
    cout << min;
    return 0;
}