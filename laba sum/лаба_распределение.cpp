#include <iostream>
#include <cmath>
#include "extension.hpp"
using namespace std;

float sum(float arr_x[1000], float arr_y[1000], float dx, int size){
    bool flag= true;
    float S = 1.0f;
    while(flag){

        if (size!=1){
            S = dx*(arr_y[size-1]+arr_y[size-2])/2;
            size--;
            S=S+sum(arr_x,arr_y,dx,size);
        }
        else{
            flag= false;
        }
    }
    return S;
}

int main(){
    float x = 10.0f;
    float T = 273.0f;
    float c =sqrt(T*M_PI);
    int size =16;
    float dv= x/size;
    float arr_v[size]={0.0f};
    float arr_f[size]={0.0f};
    for(int i=0; i<size;++i){
        if(i!=(size-1)/2){
            arr_v[i]=(i-(size-1)/2)*dv;
        }
        else{
            arr_v[i]=0;
        }
    }
    for(int i=0; i<size;++i){
        arr_f[i]= exp(-pow(arr_v[i],2)/T)/c;
    }
    float S =sum(arr_v,arr_f,dv,size);
    cout<<"S="<<S;
    return 0;
}
