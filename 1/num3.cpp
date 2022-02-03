#include <iostream>
using namespace std;

int main() {
    int x = 0;
    int y = 0;
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
    long long P = 1;
    for (unsigned int i = 0; i < y; ++i){
         P = P*x;
        }
    cout << P;
    return 0;
}


