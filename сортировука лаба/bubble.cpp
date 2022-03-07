#include <iostream>
#include <ctime>
#include "extension.hpp"
using namespace std;

void  bubble_sort(long long arr[50000], long long Max_N){
    for(long long i=0;i<Max_N;++i){
        for(long long j=0; j<Max_N-(i+1);++j){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
            }
        }
    }


int main(){
    srand(time(0));
    long long MAX_N=15;
    long long arr[MAX_N]={0};
    for(long long i=0;i<MAX_N;++i){
        arr[i]=rand()%10000+1;
    }

    bubble_sort(arr,MAX_N);
   /* for(long long i=0;i<MAX_N;++i){
        cout<<arr[i]<<" ;";
    }*/
    cout << "runtime = " << clock()*100000 << endl; // время работы программы
    system("pause");
    return 0;
};
