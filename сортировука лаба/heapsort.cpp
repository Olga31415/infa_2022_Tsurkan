#include <iostream>
using namespace std;

void heap_trans(int arr[1000], int N, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < N and arr[left] > arr[largest]){
        largest = left;
    }
    if (right < N and arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i){
        swap(arr[i], arr[largest]);
        heap_trans(arr, N, largest);
    }
}

void heapsort(int arr[1000], int N){
    for (int i = N / 2 - 1; i >= 0; i--){
        heap_trans(arr, N, i);
    }
    for (int i=N-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heap_trans(arr, i, 0);
    }
}

int main(){
    srand(time(NULL));
    int N = 1000;
    int arr[1000]={0};
    for( int i=0; i<N;++i){
        arr[i]=rand()%2000+1;
    }

   heapsort(arr, N);

    for(int i = 0;i<N;++i){
        cout<<arr[i]<<"; ";
    }
    return 0;
}