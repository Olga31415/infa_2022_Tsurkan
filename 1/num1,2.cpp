#include <iostream>
using namespace std;

int main() {
    cout << "Tsurkan Olga " << "112 " << "LFI FOPF " << endl;

    unsigned int N;
    cout << "N=";
    cin >> N;
    if (N%5==0){
        for(unsigned int i = 0; i < N; ++i){
            cout <<"@";
        }
    }
    if (N%5!=0){
        for(unsigned int i = 0; i < N; ++i){
            cout <<"%";
        }
    }
    return 0;
}
