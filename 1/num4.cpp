#include <iostream>
using namespace std;

int main() {
    int N = 0;
    cout << "N=";
    cin >> N;
    int min = INT_MAX;
    int x = 0;
    for (unsigned int i = 0; i < N; ++i){
        cin >> x;
        if (x<min){
            min=x;
        }
    }
    cout << min;
    return 0;
}

