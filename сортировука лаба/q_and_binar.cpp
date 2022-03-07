#include <iostream>
#include "extension.hpp"
using namespace std;

int MAX_N =450000;

void quicksort(int arr[450000], int first, int last){
int mid;
int f=first, l=last;
mid=arr[(f+l)/2];
do{
    while (arr[f]<mid) f++;
    while (arr[l]>mid) l--;
    if (f<=l){
        swap(arr[f],arr[l]);
        f++;
        l--;
    }
}
while (f<l);
if (first<l){quicksort(arr, first, l);}
if (f<last){quicksort(arr, f, last);}

}

int binary_search(int arr[],int Max_N, int search_element){
    int l=0, r=Max_N-1;
    int mid=0;
    bool flag=false;
    while(l<=r and flag!=true){
        mid=(l+r)/2;
        if(arr[mid]==search_element){
            flag=true;
        }
        if (arr[mid]>search_element){
            r=mid+1;
        }
        if(arr[mid]<search_element){
            l=mid-1;
        }
    }
    return mid;
}

int main(){
    srand(time(0));
    int arr[MAX_N]={0};
    for(int i=0;i<MAX_N;++i){
        arr[i]=rand()%2000+1;
    }
    int first=0, last = MAX_N-1;
    quicksort(arr,first,last);
    /*for(int i=0;i<MAX_N;++i){
        cout<<arr[i]<<';';
    }*/
    //cout<<"enter key element";
    int key_element=0;
    int num=300000;
    //cin>>key_element;
    for(int i =0;i<num;++i){
        key_element=rand()%500+1;
        int mid=binary_search(arr,MAX_N,key_element)+1;
        //cout<<mid<<endl;
        }



    cout << "runtime = " << clock()/1000.0 << endl; // время работы программы
    system("pause");
    return 0;
}
