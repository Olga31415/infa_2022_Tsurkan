#include <iostream>
using namespace std;

bool prime_number(unsigned long long num) {
    unsigned long long i = 2;
    unsigned long long k = 2;
    char bool_number = true;
    while (i < num) {
        unsigned long long a = num % i;
        if (a == 0) {
            k += 0;
        }
        if (a != 0) {
            k += 1;
        }
        ++i;
    }
    if (k != num) {
        bool_number = false;
    }
    return bool_number;
}

unsigned long long next_prime(unsigned long long num){
    unsigned long long inter= num+1;
    char chek = prime_number(inter);
    while(chek == false){
        inter+=1;
        chek = prime_number(inter);
    }
    return inter;

}

int main(){
    unsigned long long a=2;
    char ent = 0;
    while (cin >> ent and ent !='@'){
    a = next_prime(a);
    cout<<a<<endl;}

    return 0;
};
