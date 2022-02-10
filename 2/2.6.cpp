#include <iostream>
using namespace std;

unsigned long long fib(int n){
    unsigned long long a = 1;
    unsigned long long b = 1;
    unsigned long long c;
    if(n==1 or n==2){
        c=1;
    }
    else{
        for(unsigned long long  i=2; i<n;++i){
            c=a+b;
            a=b;
            b=c;
        }}

    return c;

}

int main(){
    int N = 0;
    cin>>N;
    if(N > 0 and N<=50){
        cout<<fib(N);
    }

    else{
        cout<<"invalid number";
    }
    return 0;
};

