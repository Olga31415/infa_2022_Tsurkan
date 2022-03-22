#include <iostream>
#include <cmath>
#include "extension.hpp"
using namespace std;

float sum(float arr_x[10000], float arr_y[10000], float dx, int size){
    int step = 1;
    while(step*2<=size){
        int i=0;
        while (i<size){
            arr_y[i]=arr_y[i]+arr_y[i+step];
            i+=step*2;

        }
        step=step*2;
    }
    return arr_y[0]*dx;
}

int main(){
    float x = 400.0f;
    float T = 273.0f;
    float c =sqrt(T*M_PI);
    int size =1024;
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
