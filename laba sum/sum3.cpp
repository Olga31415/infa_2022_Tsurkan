#include <iostream>
#include <cmath>
#include "extension.hpp"
using namespace std;

float sum_kahan(float arr_x[10000], float arr_y[10000], float dx, int size){
    float sum = 0.0f;
    float ch=0.0f;
    for (int i =0; i<size;++i){
        float y = arr_y[i]-ch;
        float t = sum+y;
        ch=t-sum-y;
        sum=t;
    }
    return sum*dx;
}

int main(){
    float x = 1000.0f;
    float T = 273.0f;
    float c =sqrt(T*M_PI);
    int size =8192;
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
    float S = sum_kahan(arr_v,arr_f,dv,size);
    cout<<"S="<<S;
    return 0;
}

