#include <iostream>
using namespace std;

unsigned long long factorial(int N){
    if (N==0) {
        return 1;}
    else {
        return N*factorial(N-1);
    }
}

int main(){
    int N;
    cin>>N;
    if(N<=20){
        cout<<factorial(N);
    }
    else{
        cout<<"invalid number";
    }
    return 0;
};
