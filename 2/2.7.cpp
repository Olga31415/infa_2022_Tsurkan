#include <iostream>
using namespace std;

void binary(unsigned long long value){
    if(value == 1 or value == 0){
        cout << value;
        return;
    }
    binary(value / 2);
    cout << value % 2;
    return;
}

int main(){
    unsigned long long n;
    cin>>n;
    binary(n);
    return 0;
}
