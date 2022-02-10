#include <iostream>
using namespace std;

unsigned long long check_sim(char ch, unsigned  long long number){
    if('0'<=ch && ch<='9'){
        number = number*10+ch-'0';
    }
    return number;
}
int main(){
    char a;
    unsigned long long b = 0;
    while(cin>>a && a!='@'){
        b=check_sim(a, b);
    }
    cout << b;
    return 0;
}

