#include <iostream>
using namespace std;

bool prime_number(unsigned long long num){
    unsigned long long i = 2;
    unsigned long long k = 2;
    char bool_number = true;
    while(i<num) {
        unsigned long long a = num%i;
        if(a == 0) {
            k+=0;
        }
        if(a!=0){
            k+=1;
        }
        ++i;
    }
    if(k!=num){
        bool_number=false;
    }
   return bool_number;
}
int main() {
    unsigned long long num;
    cin>>num;
    auto v = prime_number(num);
    if(v==true){
        cout<<"prime number";
    }
    else{
        cout<<"composite number";
    }
    return 0;
}
