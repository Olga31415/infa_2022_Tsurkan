#include <iostream>
#include <cmath>
#include "extension.hpp"
using namespace std;

struct objects{
    char thing;
    char terms[5];
    int amount;
    int price;
};

int counter(objects arr[6],char n){
    objects arr1;
    int S =0;
        for(int i=0;i<6;++i){
            if(n==arr[i].thing){
                S+=arr[i].price;
                arr1=arr[i];
            }
        }
    if(arr1.terms[0]!='0'){
        for(int i=0;i< arr1.amount;++i){
            S+=counter(arr,arr1.terms[i]);

        }
    }
    return S;
}

int main(){
    int m=6;
    objects arr[6]={};
    for(int i=0;i<m;++i){
        cout<<i+1<<':';
        cin>>arr[i].thing>>arr[i].terms>>arr[i].amount>>arr[i].price;
    }
    char n;
    cin>>n;
    cout<<counter(arr,n);
    return 0;
}

