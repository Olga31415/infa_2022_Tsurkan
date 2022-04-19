#include <iostream>
#include <cstring>
using namespace std;

struct values{
    int value;
    int num_of_coins;

};

int min(int a, int b){
    int check;
    if(a<=b){
        check=a;
    }
    if(a>b){
        check=b;
    }
    return check;
}

void count(int coin[5], values *arr, int N){
    for (int i=0; i<N;++i){
        arr[i].value=i;
        arr[i].num_of_coins=1000;
        if(arr[i].value==0){
            arr[i].num_of_coins=0;
        }
        int n;
        for(int j=0;j<5;++j){

            if(arr[i].value==coin[j]){
                arr[i].num_of_coins=1;
            }
            if(arr[i].value>coin[j]){
                int x = coin[j];
                n=arr[i].num_of_coins;
                arr[i].num_of_coins=1+arr[i-x].num_of_coins;
                arr[i].num_of_coins=min(arr[i].num_of_coins,n);
            }

        }
    }
    cout<< arr[N-1].num_of_coins;
}

int main(){
    int coin[5]={1,2,5,7,10};
    int n;
    cin>>n;
    auto arr = new values[n+1];
    int N=n+1;
    count(coin,arr,N);
    return 0;
}

